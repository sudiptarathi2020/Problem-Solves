#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll N,X;cin>>N>>X;
    ll a[N];for(ll &x:a)cin>>x;
    ll dp[X+1];memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(ll x:a){
        for(ll i=1;i<=X;i++){
            if(i>=x){
                dp[i]+=dp[i-x];
                dp[i]%=mod;
            }
        }
    }
    cout<<dp[X]<<endl;
    return 0;
}
