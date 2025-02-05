
#include<bits/stdc++.h>
using namespace std;
#define mid ((start+end)>>1)
#define lc (node+1)
#define rc (((mid-start+1)<<1)+node)
const int N = 100005;
long long segtree[N<<1],arr[N];
void build(int start,int end,int node){
    if(start==end){
        segtree[node] = arr[start];
        return;
    }
    build(start,mid,lc);
    build(mid+1,end,rc);
    segtree[node] = segtree[lc]+segtree[rc];
}
long long query(int start,int end,int node,int left,int right){
    if(start>right or end<left)return 0LL;
    if(start>=left and end<=right)return segtree[node];
    return query(start,mid,lc,left,right)+query(mid+1,end,rc,left,right);
}
void update(int start,int end, int node, int idx,int val){
    if(start==end){
        segtree[node] = (long long)val;
        return;
    }
    if(idx<=mid)update(start,mid,lc,idx,val);
    else update(mid+1,end,rc,idx,val);
    segtree[node] = segtree[lc]+segtree[rc];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++)cin>>arr[i];
    build(0,n-1,0);
    while(q--){
        int choice;cin>>choice;
        if(choice&1){
            int idx,val;cin>>idx>>val;
            update(0,n-1,0,idx,val);
        }else{
            int left,right;cin>>left>>right;
            cout<<query(0,n-1,0,left,right-1)<<endl;
        }
    }
}
