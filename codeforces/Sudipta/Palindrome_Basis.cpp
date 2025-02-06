#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
const int N=4e4+10;
const int M=500;
const int mod=1e9+7;
using namespace std;
vector<ll>v;
vector<vector<ll>>dp(N+1,vector<ll>(M+2));
#define all(s) (s).begin(),(s.end())
void sol(){
    ll n;cin>>n;
    cout<<dp[n][(ll)v.size()-1]<<endl;
}
bool ispal(string s){
    string ss=s;
    reverse(all(s));
    return ss==s;
}
int main(){
    for(ll i=1;i<=N;i++){
        if(ispal(to_string(i))){
            v.push_back(i);
        }
    }
    //cout<<v.size()<<endl;
    for(ll i=0;i<=N;i++){
        dp[i][0]=1;
    }
    for(ll i=0;i<M-2;i++){
		dp[0][i]=1;
	}
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<(ll)v.size();j++){
            if(v[j]<=i){
                dp[i][j]=dp[i][j-1]+dp[i-v[j]][j];
                dp[i][j]%=mod;
            }else{
                dp[i][j]=dp[i][j-1];
            }

        }
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
