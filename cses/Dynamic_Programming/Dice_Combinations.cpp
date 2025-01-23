#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
vector<ll>dp;
ll ok(ll N){
    if(N<0)return 0;
    if(N==0)return 1;
    if(N==1)return 1;
    if(dp[N]!=-1)return dp[N];
    dp[N]=ok(N-1)+ok(N-2)+ok(N-3)+ok(N-4)+ok(N-5)+ok(N-6);
    dp[N]%=mod;
    return dp[N];
}
int main(){
    ll n;cin>>n;
    dp.resize(n+1,-1ll);
    cout<<ok(n)<<endl;
}
