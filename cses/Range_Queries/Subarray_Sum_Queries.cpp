#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
const int N=200050;
struct Data{
    ll  sum,pref,suff,ans;
};
Data tree[N<<2];
Data combine(Data l,Data r){
    Data R;
    R.sum=l.sum+r.sum;
    R.pref=max(l.pref,l.sum+r.pref);
    R.suff=max(r.suff,r.sum+l.suff);
    R.ans=max({r.ans,l.ans,l.suff+r.pref});
    return R;
}
Data make(ll val){
    Data res;
    res.sum=res.pref=res.suff=res.ans=val;
    return res;
}
void build(int node,int start,int end,ll arr[]){
    if(start==end){
        tree[node]=make(arr[start]);
    }else{
        int mid=(start+end)>>1;
        build(node<<1,start,mid,arr);
        build(node<<1|1,mid+1,end,arr);
        tree[node]=combine(tree[node<<1],tree[node<<1|1]);
    }
}
void upd(int node,int start,int end,int pos,ll val){
    if(start==end){
        tree[node]=make(val);
    }else{
        int mid=(start+end)>>1;
        if(pos<=mid)
            upd(node<<1,start,mid,pos,val);
        else
            upd(node<<1|1,mid+1,end,pos,val);
        tree[node]=combine(tree[node<<1],tree[node<<1|1]);
    }
}
Data ans(int node,int start,int end,int left,int right){
    if(start==left and right==end){
        return tree[node];
    }
    int mid=(start+end)>>1;
    if(right<=mid){
        return ans(node<<1,start,mid,left,right);
    }else if(mid<left){
        return ans(node<<1|1,mid+1,end,left,right);
    }else{
        return combine(ans(node<<1,start,mid,left,mid),ans(node<<1|1,mid+1,end,mid+1,right));
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;cin>>n>>m;
    ll  arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    build(1,0,n-1,arr);
    while(m--){
        int pos;
        ll val;
        cin>>pos>>val;
        pos--;
        upd(1,0,n-1,pos,val);
        cout<<max(tree[1].ans,0LL)<<endl;
    }
    return 0;
}
