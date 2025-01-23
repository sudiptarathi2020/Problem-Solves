
// Add some code
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=16;
ll dp[N][1<<N];
ll arr[N][N];
ll n;
ll ok(ll ind,ll mask){
    if(mask==(1<<n)-1)return 0;
    if(dp[ind][mask]!=-1)return dp[ind][mask];
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(!(mask&(1<<i))){
            ans=max(ans,arr[ind][i]+ok(ind+1,mask|(1<<i)));
        }
    }
    return dp[ind][mask]=ans;
}
void sol(ll test){
    cin>>n; 
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof dp);
    cout<<"Case "<<test<<": ";
    cout<<ok(0,0)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n;cin>>n;
    for(ll i=1;i<=n;i++)sol(i);
}
