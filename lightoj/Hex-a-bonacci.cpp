
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<ll,ll>;
using namespace std;
const ll N=10010;
const ll mod=10000007;
ll arr[N];
void sol(ll test){
    for(ll i=0;i<6;i++){
        cin>>arr[i];
    }
    ll n;cin>>n;
    for(ll i=6;i<=n;i++){
        arr[i]=(arr[i-1]+arr[i-2]+arr[i-3]+arr[i-4]+arr[i-5]+arr[i-6])%mod;
    }
    cout<<"Case "<<test<<": "<<arr[n]%mod<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;
    cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}

