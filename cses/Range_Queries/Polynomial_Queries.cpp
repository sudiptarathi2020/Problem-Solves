#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((start+end)>>1)
#define lc (node+1)
#define rc (((mid-start+1)<<1)+node)
const ll N=2e5+10;
ll tree[N<<1],llz[N<<1],rlz[N<<1];
void build(ll node,ll start,ll end,ll arr[]){
    if(start==end){
        tree[node]=arr[start];
    }else{
        build(lc,start,mid,arr);
        build(rc,mid+1,end,arr);
        tree[node]=tree[lc]+tree[rc];
    }
}
void upd(ll node,ll start,ll end,ll lvalue,ll rvalue){
    tree[node]+=(end-start+1)*lvalue+(rvalue*(end*(end+1)-start*(start-1))>>1);
    llz[node]+=lvalue;rlz[node]+=rvalue;
}
void push(ll node,ll start,ll end){
    upd(lc,start,mid,llz[node],rlz[node]);
    upd(rc,mid+1,end,llz[node],rlz[node]);
    llz[node]=rlz[node]=0;
}
void upd(ll node,ll start,ll end,ll left,ll right,ll lvalue,ll rvalue){
    if(left<=start && right>=end){
        upd(node,start,end,lvalue,rvalue);
        return;
    }
    push(node,start,end);
    if(left<=mid){
        upd(lc,start,mid,left,right,lvalue,rvalue);
    }
    if(right>mid){
        upd(rc,mid+1,end,left,right,lvalue,rvalue);
    }
    tree[node]=tree[lc]+tree[rc];
}
ll Q(ll node,ll start,ll end,ll left,ll right){
    if(left<=start && right>=end){
        return tree[node];
    }
    push(node,start,end);
    ll a=left<=mid?Q(lc,start,mid,left,right):0;
    ll b=right>mid?Q(rc,mid+1,end,left,right):0;
    return a+b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,q;cin>>n>>q;ll arr[n];
    for(ll &i:arr)cin>>i;
    build(0,0,n-1,arr);
    while(q--){
        ll ch,l,r;cin>>ch>>l>>r;l--,r--;
        if(ch==1){
            upd(0,0,n-1,l,r,1-l,1);
        }else{
            cout<<Q(0,0,n-1,l,r)<<endl;
        }
    }
}
