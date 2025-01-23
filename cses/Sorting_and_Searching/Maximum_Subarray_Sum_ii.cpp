#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<ll,ll>;
using namespace std;
const ll N=200050,lg=19;
ll sp[lg+1][N];
int Lg(int r){
    return __bit_width(r)-1;
}
ll Min(ll l,ll r){
    ll i=Lg(r-l+1);
    return min(sp[i][l],sp[i][r-(1<<i)+1]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,a,b;cin>>n>>a>>b;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(i){
            arr[i]+=arr[i-1];
        }
    }
    for(ll i=0;i<n;i++){
        sp[0][i]=arr[i];
    }
    for(ll i=1;i<=lg;i++){
        for(ll j=0;j+(1<<i)<=n;j++){
            sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
        }
    }
    ll ans=arr[a-1];
    for(ll i=a;i<n;i++){
        ll F=max(0ll,i-b);
        ll S=max(0ll,i-a);
        ll k=Min(F,S);
        ans=max(ans,arr[i]-k);
        if(i-b<0){
            ans=max(ans,arr[i]);
        }
    }
    cout<<ans<<endl;
}
