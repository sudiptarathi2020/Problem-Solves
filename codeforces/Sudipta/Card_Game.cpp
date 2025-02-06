#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
const int N=61;
const ll mod=998244353;
using namespace std;
vector<vector<ll>>c(N+1,vector<ll>(N+1,0));
void sol(){
    ll n;cin>>n;
    int cnt=0;
    ll ans=0,ans1=0;
    for(ll i=n;i>=4;i-=2){
        if(cnt&1){
            ans+=c[i-2][(i/2)-2];
            ans%=mod;
        }else{
            ans+=c[i-1][(i/2)-1];
            ans%=mod;
        }
        cnt++;
    }
    cnt=0;
    for(ll i=n;i>=4;i-=2){
        if(cnt&1){
            ans1+=c[i-1][(i/2)-1];
            ans1%=mod;
        }else{
            ans1+=c[i-2][(i/2)-2];
            ans1%=mod;
        }
        cnt++;
    }
    if(n%4==0){
        ans1++;
        ans1%=mod;
    }else{
        ans++;
        ans%=mod;
    }
    cout<<ans<<" "<<ans1<<" "<<1<<endl;
}
int main(){
    c[0][0]=1;
    for(ll i=1;i<=N;i++){
        c[i][0]=c[i][i]=1;
        for(ll k=1;k<i;k++){
            c[i][k]=c[i-1][k-1]+c[i-1][k];
            c[i][k]%=mod;
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
