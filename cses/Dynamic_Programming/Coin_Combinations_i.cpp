#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,x;cin>>n>>x;
    ll coins[n];
    for(int i=0;i<n;i++)cin>>coins[i];
    ll pos[x+1];
    memset(pos,0,sizeof(pos));
    pos[0]=1;
    for(ll i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(coins[j]<=i){
                pos[i]+=pos[i-coins[j]];
                if(pos[i]>=mod)pos[i]-=mod;
            }
        }
    }
    cout<<pos[x]<<endl;
    return 0;
}
