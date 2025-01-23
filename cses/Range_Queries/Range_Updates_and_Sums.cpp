#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct vertex{
    ll sm;
    ll lazy;
    bool x;
    vertex(){
        sm=lazy=x=0;
    }
}st[1<<19];
void app(ll node,ll val,bool xx,ll start,ll end){
    if(xx){
        st[node].sm=0;
        st[node].lazy=0;
        st[node].x=true;
    }
    st[node].sm+=(end-start+1)*val;
    st[node].lazy+=val;
}
void push(ll node,ll start,ll mid,ll end){
    app(node+node,st[node].lazy,st[node].x,start,mid);
    app(node+node+1,st[node].lazy,st[node].x,mid+1,end);
    st[node].lazy=0;
    st[node].x=0;
}
void upd(ll node,ll start,ll end,ll left,ll right,ll val,bool x){
    if(left<=start&&end<=right){
        app(node,val,x,start,end);
        return;
    }
    ll mid=(start+end)>>1;
    push(node,start,mid,end);
    if(left<=mid){
        upd(node+node,start,mid,left,right,val,x);
    }
    if(mid<right){
        upd(node+node+1,mid+1,end,left,right,val,x);
    }
    st[node].sm=st[node+node].sm+st[node+node+1].sm;
}
ll query(ll node,ll start,ll end,ll left,ll right){
    if(left<=start and end<=right){
        return st[node].sm;
    }
    ll mid=(start+end)>>1;
    push(node,start,mid,end);
    return (left<=mid?query(node+node,start,mid,left,right):0)+(mid<right?query(node+node+1,mid+1,end,left,right):0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll T;cin>>T;
    vector<ll>arr(T);
    ll Q;cin>>Q;
    for(ll i=0;i<T;i++){
        cin>>arr[i];
        upd(1,0,T-1,i,i,arr[i],0);
    }
    for(ll i=1;i<=Q;i++){
        ll ch;cin>>ch;
        if(ch==1){
            ll a,b,c;cin>>a>>b>>c;
            a--,b--;
            upd(1,0,T-1,a,b,c,0);
        }else if(ch==2){
            ll a,b,c;cin>>a>>b>>c;
            a--,b--;
            upd(1,0,T-1,a,b,c,1);
        }else{
            ll a,b;cin>>a>>b;
            a--,b--;
            cout<<query(1,0,T-1,a,b)<<endl;
        }
    }
}
