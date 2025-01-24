
#include<bits/stdc++.h>
#include <ios>
#define ll long long
#define lc node+1
#define rc node+2*(mid-start+1)
#define F first
#define S second
using pii=std::pair<int,int>;
using namespace std;
const int mod=1e9+7;
const int N=50050;
vector<int>tree[N<<1];
void clear(){
    for(int i=0;i<(N<<1);i++){
        tree[i].clear();
    }
}
void build(int node,int start,int end,pii arr[]){
    if(start==end){
        tree[node].push_back(arr[start].second);
    }else{
        int mid=(start+end)>>1;
        build(lc,start,mid,arr);
        build(rc,mid+1,end,arr);
        size_t left=0,right=0;
        while(left<tree[lc].size() and right<tree[rc].size()){
            if(tree[lc][left]<tree[rc][right]){
                tree[node].push_back(tree[lc][left]);
                left++;
            }else{
                tree[node].push_back(tree[rc][right]);
                right++;
            }
        }
        while(left<tree[lc].size()){
            tree[node].push_back(tree[lc][left]);
            left++;
        }
        while(right<tree[rc].size()){
            tree[node].push_back(tree[rc][right]);
            right++;
        }
    }
}
int query(int node,int start,int end,int left,int right,int value1,int value2){
    if(start==left and right==end){
        int up=upper_bound(tree[node].begin(),tree[node].end(),value2)-tree[node].begin();
        int low=lower_bound(tree[node].begin(),tree[node].end(),value1)-tree[node].begin();
        return up-low;
    }else{
        int mid=(start+end)>>1;
        if(right<=mid){
            return query(lc,start,mid,left,right,value1,value2);
        }else if(mid<left){
            return query(rc,mid+1,end,left,right,value1,value2);
        }else{
            return query(lc,start,mid,left,mid,value1,value2)+query(rc,mid+1,end,mid+1,right,value1,value2);
        }
    }
}
void sol(int test){
    clear();
    int p,q;cin>>p>>q;
    pii arr[p];
    for(int i=0;i<p;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr,arr+p);
    build(0,0,p-1,arr);
    cout<<"Case "<<test<<": "<<endl;
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int pos=lower_bound(arr,arr+p,make_pair(x1,0))-arr;
        int pos2=upper_bound(arr,arr+p,make_pair(x2,1<<29))-arr;
       // cout<<pos<<" "<<pos2<<endl;
        if(pos<pos2)
            cout<<query(0,0,p-1,pos,pos2-1,y1,y2)<<endl;
        else{
            cout<<0<<endl;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
}

