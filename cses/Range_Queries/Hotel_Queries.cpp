#include<bits/stdc++.h>
using namespace std;
#define lc node+1
#define rc node+((mid-start+1)<<1)
const int N=200050;
int tree[N<<1];
void upd(int node,int start,int end,int pos,int val){
    if(start==end){
        tree[node]+=val;
    }else{
        int mid=(start+end)>>1;
        if(pos<=mid){
            upd(lc,start,mid,pos,val);
        }else{
            upd(rc,mid+1,end,pos,val);
        }
        tree[node]=max(tree[lc],tree[rc]);
    }
}
int query(int node,int start,int end,int val){
    if(start==end){
        return start;
    }
    int mid=(start+end)>>1;
    if(tree[lc]>=val){
        return query(lc,start,mid,val);
    }
    if(tree[rc]>=val){
        return query(rc,mid+1,end,val);
    }
    return -1;
}
int main(){
    int x,n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        upd(0,0,N-1,i,x);
    }
    while(m--){
        cin>>x;
        int ans=query(0,0,N-1,x);
        cout<<ans+1<<" ";
        if(ans>=0){
            upd(0,0,N-1,ans,-x);
        }
    }
}
