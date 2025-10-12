#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:

        const int N = 10010;
        vector<int>seg,lazy;
        Solution():seg(4 * N), lazy(4 * N){}
        void update(int node,int start,int end,int left,int right,int value){
            if(right<start||left>end||right<left)return;
            seg[node]+=lazy[node];
            if(end-start+1>1){
                lazy[node<<1]+=lazy[node];
                lazy[1|(node<<1)]+=lazy[node];
            }
            lazy[node]=0;
            if(left==start&&right==end){
                seg[node]+=value;
                if(end-start+1>1){
                    lazy[node<<1]+=value;
                    lazy[1|(node<<1)]+=value;
                }
                return;
            }
            int mid = (start+end)>>1;
            if(right<=mid){
                update(node<<1,start,mid,left,right,value);
            }else if(left>mid){
                update(1|(node<<1),mid+1,end,left,right,value);
            }else{
                update(node<<1,start,mid,left,mid,value);
                update(1|(node<<1),mid+1,end,mid+1,right,value);
            }
            seg[node]=seg[node<<1]+seg[1|(node<<1)];
        }
        int query(int node,int start,int end,int left,int right){
            if(right<start||left>end)return 0;
            seg[node]+=lazy[node];
            if(end-start+1>1){
                lazy[node<<1]+=lazy[node];
                lazy[1|(node<<1)]+=lazy[node];
            }
            lazy[node]=0;
            if(left==start&&right==end){
                return seg[node];
            }
            int mid = (start+end)>>1;
            if(right<=mid){
                return query(node<<1,start,mid,left,right);
            }else if(left>mid){
                return query(1|(node<<1),mid+1,end,left,right);
            }else{
                return query(node<<1,start,mid,left,mid)+query(1|(node<<1),mid+1,end,mid+1,right);
            }
        }
        void print(size_t n){
            cout<<"\n------------------------------\n";
            for(int i=1;i<n<<2;i++){
                cout<<seg[i]<<" ";
            }
            cout<<endl;
            for(int i=1;i<n<<2;i++){
                cout<<lazy[i]<<" ";
            }
            cout<<endl;
            cout<<"\n------------------------------\n";
        }
        bool canJump(vector<int>&nums){
            int n=(int)nums.size();
            if(n==1)return true;
            for(int i=0;i<n;i++){
                cout<<nums[i]<<" "<<query(1,0,n-1,i,i)<<endl;
                if(i==n-1)return true;
                if(nums[i]==0 and query(1,0,n-1,i+1,i+1)==0){
                    return false;
                }
                update(1,0,n-1,i+1,i+nums[i],1);
                // print(nums.size());
            }
            return query(1,0,n-1,n-1,n-1)>0;
        }


};
