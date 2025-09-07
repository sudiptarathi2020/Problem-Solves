#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void update(vector<int>&seg,vector<int>&lazy,int node,int start,int end,int left,int right,int value=1){
            seg[node]+=(end-start+1)*lazy[node];
            if(start!=end){
                lazy[node<<1]+=lazy[node];
                lazy[1|(node<<1)]+=lazy[node];
            }
            lazy[node]=0;
            if(start == left && end == right){
                seg[node]+=(end-start+1)*value;
                if(start!=end){
                    lazy[node<<1]+=value;
                    lazy[1|(node<<1)]+=value;
                }
                return;
            }
            int mid = (start+end)>>1;
            if(right<=mid){
                update(seg,lazy,node<<1,start,mid,left,right);
            }else if(left>mid){
                update(seg,lazy,1|(node<<1),mid+1,end,left,right);
            }else{
                update(seg,lazy,node<<1,start,mid,left,mid);
                update(seg,lazy,1|(node<<1),mid+1,end,mid+1,right);
            }
            seg[node]=seg[node<<1]+seg[1|(node<<1)];
        }
        int query(vector<int>&seg,vector<int>&lazy,int node,int start,int end,int left,int right){
            seg[node]+=(end-start+1)*lazy[node];
            if(start!=end){
                lazy[node<<1]+=lazy[node];
                lazy[1|(node<<1)]+=lazy[node];
            }
            lazy[node]=0;
            if(start == left && end == right){
                return seg[node];
            }
            int mid = (start+end)>>1;
            if(right<=mid){
                return query(seg,lazy,node<<1,start,mid,left,right);
            }else if(left>mid){
                return query(seg,lazy,1|(node<<1),mid+1,end,left,right);
            }else{
                return query(seg,lazy,node<<1,start,mid,left,mid)+query(seg,lazy,1|(node<<1),mid+1,end,mid+1,right);
            }

        }
        /*
           vector<vector<int>> merge(vector<vector<int>>& intervals){
           const int N = 10010;
           vector<int>seg(N<<2),lazy(N<<2);
           for(auto interval: intervals){
           update(seg,lazy,1,0,N-1,interval[0],interval[1]);
           }
           int turn = 0,first=-1,second=-1;
           vector<vector<int>>answer;
           for(int i=0;i<N;i++){
           if(query(seg,lazy,1,0,N-1,i,i)==0){
           if(turn==1){
           answer.push_back(vector<int>{first,second});
           turn=0;
           }
           }else{
           if(turn==0){
           turn = 1;
           first = i;
           }else{
           second = i;
           }
           }
           }
           return answer;
           }
           */
        vector<vector<int>> merge(vector<vector<int>>& intervals){
            const int N = 10010;
            vector<int>nums(N);
            for(auto interval:intervals){
                nums[interval[0]]=1;
                nums[interval[2]]=2;
            }
            stack<pair<int,int>>stk;
            for(int i=0;i<N;i++){
                if(nums[i]==1){
                    stk.push({nums})
                }else if(nums[i]==2){

                }
            }
        }
};
int main(){

}









