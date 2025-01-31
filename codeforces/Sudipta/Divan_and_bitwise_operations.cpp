#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
using namespace std;
struct seg{
    vector<ll>tree;
    vector<ll>lazy;
    vector<ll>lval;
    ll N;
    seg(ll n){
        N=n;
        tree.assign(4*n,0);
        lazy.assign(4*n,0);
        lval.assign(4*n,0);
    }
    void build(vector<ll>&arr,ll node,ll st,ll en){
        if(st==en){
            tree[node]=arr[st];
            return;
        }
        ll mid=(st+en)/2;
        build(arr,2*node,st,mid);
        build(arr,2*node+1,mid+1,en);
        tree[node]=tree[2*node] & tree[2*node+1];
    }
    void update(ll node,ll st,ll en,ll l,ll r,ll val){
        if(lazy[node]!=0){
            tree[node]&=lval[node];
            if(st!=en){
                lazy[2*node]=true;
                lval[2*node]=lval[node];
                lval[2*node+1]=lval[node];
                lazy[2*node+1]=true;
            }
            lazy[node]=0;
        }
        if(en<l||st>r){
            return ;
        }
        if(st==l and en==r){
            tree[node]&=val;
            if(st!=en){
                lazy[2*node]=true;
                lval[2*node]=val;
                lazy[2*node+1]=true;
                lval[2*node+1]=val;
            }
            return;
        }
        ll mid=(st+en)/2;
        if(r<=mid){
            update(2*node,st,mid,l,r,val);
        }else if(l>mid){
            update(2*node+1,mid+1,en,l,r,val);
        }else{
            update(2*node,st,mid,l,mid,val);
            update(2*node+1,mid+1,en,mid+1,r,val);
        }
        tree[node]=tree[node*2] & tree[2*node+1];
    }
    ll query(ll node,ll st,ll en,ll l,ll r){
        if(lazy[node]!=0){
            tree[node]&=lval[node];
            if(st!=en){
                lazy[2*node]=true;
                lval[2*node]=lval[node];
                lazy[2*node+1]=true;
                lval[2*node+1]=lval[node];
            }
            lazy[node]=false;
        }
        if(en<l||st>r){
            return 0;
        }
        if(l==st && en==r){
            return tree[node];
        }
        ll k,p;
        ll mid=(st+en)/2;
        if(r<=mid){
            return query(2*node,st,mid,l,r);
        }else if(l>mid){
            return query(2*node+1,mid+1,en,l,r);
        }else{
            k =query(2*node,st,mid,l,mid);
            p= query(2*node+1,mid+1,en,mid+1,r);
            //return k & p;
        }
        //tree[node]=tree[node*2] & tree[2*node+1];
        return k & p;
    }
    void build(vector<ll>&v){
        build(v,1,0,N-1);
    }
    void update(ll left,ll right,ll val){
        update(1,0,N-1,left,right,val);
    }
    ll query(ll left,ll right){
        return query(1,0,N-1,left,right);
    }
};
long long binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void sol()
{
    ll n;cin>>n;
    vector<ll>v(n,(1LL<<30)-1);
    seg seg1(n);
    seg1.build(v);
    ll m;cin>>m;
    for(ll i=0;i<m;i++){
        ll a,b,c;cin>>a>>b>>c;
        seg1.update(a-1,b-1,c);
    }
    vector<ll>arr;
    for(ll i=0;i<n;i++){
        arr.push_back(seg1.query(i,i));
    }
    //for(ll I:arr){
    //	cout<<I<<" ";
    //}
    //cout<<endl
    //seg1.update(0,3,5);
    //seg1.update(3,7,2);
    //for(ll i=0;i<n;i++){
    //cout<<seg1.query(i,i)<<" ";
    //}
    ll ans=0;
    for(ll i=0;i<=30;i++){
        ll cnt=0;
        for(ll j=0;j<n;j++){
            if(arr[j] & (1<<i)){
                cnt++;
            }
        }
        if(cnt){
            ans+=(1LL<<i)*binpow(2,n-1)%mod;
            ans%=mod;
        }
    }
    cout<<ans<<endl;
    return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    //cout<<mod<<endl;
    ll t;cin>>t;
    while(t--)sol();
    return 0;
}
