//https://codeforces.com/problemset/problem/920/F
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e5+1;
const ll maxn=1e6+1;
ll primes[maxn+1];
ll DD[maxn+1];
pair<ll,ll> t[4*N];
void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = make_pair(a[tl],a[tl]);
    } else {
        ll tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v].first = t[v*2].first + t[v*2+1].first;
        t[v].second=max(t[v*2].second,t[v*2+1].second);
    }
}
ll sum(ll v, ll tl, ll tr, ll l, ll r) {
    if(tl==l and tr==r){
        return t[v].first;
    }
    ll mid=(tl+tr)>>1;
    if(r<=mid){
        return sum(v*2,tl,mid,l,r);
    }else if(mid<l){
        return sum(2*v+1,mid+1,tr,l,r);
    }else{
        ll a=sum(2*v,tl,mid,l,mid);
        ll b=sum(2*v+1,mid+1,tr,mid+1,r);
        return a+b;
    }
}
ll D(ll x){
    ll ans=1;
    ll y=x;
    if(DD[y]!=-1)return DD[y];
    while(x!=1){
        ll cnt=1;
        ll k=primes[x];
        while(x%k==0){
            cnt++;
            x/=k;
        }
        ans*=cnt;
    }
    return DD[y]=ans;
}
void update(ll v, ll start, ll end, ll left,ll right) {
    if(t[v].second<=2)return;
    if(start==end){
        ll x=D(t[v].first);
        t[v]=make_pair(x,x);
        return;
    }
    ll mid=(start+end)/2;
    if(right<=mid){
        update(2*v,start,mid,left,right);
    }else if(mid<left){
        update(2*v+1,mid+1,end,left,right);
    }else{
        update(2*v,start,mid,left,mid);
        update(2*v+1,mid+1,end,mid+1,right);
    }
    t[v].first = t[v*2].first + t[v*2+1].first;
    t[v].second=max(t[v*2].second,t[v*2+1].second);

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    iota(primes,primes+maxn+1,0);
    for(ll i=2;i*i<=maxn;i++){
        if(primes[i]==i){
            for(ll j=i*i;j<=maxn;j+=i){
                primes[j]=min(primes[j],i);
            }
        }
    }
    memset(DD,-1,sizeof(DD));
    ll n,q;
    scanf("%lld%lld",&n,&q);
    ll arr[n];
    for(ll i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    build(arr,1,0,n-1);
    while(q--){
        ll a,b,c;scanf("%lld%lld%lld",&a,&b,&c);
        b--,c--;
        if(a==1){
            update(1,0,n-1,b,c);
        }else{
            printf("%lld\n",sum(1,0,n-1,b,c));
        }
    }
    return 0;
}
