
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define mkp make_pair
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
#define IN cin
#define out cout
#define elif else if
#define yes cout<<"yes\n";
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define no cout<<"no\n";
#define fst first
#define scnd second
#define all(s) (s).begin(),(s.end())
#define sz(x) (ll)(x).size();
#define FOR(i,a,b) for(ll i=a;i<(b);i++)
#define F0R(i,a) for(ll i=0;i<(a);i++)
#define FORd(i,a,b) for(ll i=a;i>=b;i--)
#define F0Rd(i,a) for(ll i=a;i>=0;i--)
using namespace std;
const ll inf=LLONG_MAX;
const ll ninf=LLONG_MIN;
const ll N=2e5;
const ll mod=1e8+7;
typedef pair<ll,ll> pl;
typedef set<ll> st;
typedef queue<ll> ql;
typedef queue<pl> qpl;
typedef stack<ll> stk;
typedef stack<pl> stkp;
typedef priority_queue<ll> pq;
typedef priority_queue<ll,vector<ll>,greater<ll>> rpq;
typedef priority_queue<pl> pql;
typedef priority_queue<pl,vector<pl>,greater<pl>> rpql;
typedef set<pl> stp;
typedef vector<ll> vl;
typedef set<ll,greater<ll>> rst;
typedef set<pl,greater<pl>> rstp;
typedef vector<pl> vpl;
typedef vector<string> vs;
vector<int>val,num;
vector<vector<int>>dp;
int n;
int OK(int ind,int REM){
    //if(ind==n)return 0; 
    if(REM==0)return 1;
    if(ind==n)return 0;
    if(dp[ind][REM]!=-1)return dp[ind][REM];
    dp[ind][REM]=0;
    for(int i=0;i<=num[ind] and REM-i*val[ind]>=0;i++){
        dp[ind][REM]+=OK(ind+1,REM-i*val[ind])%mod;
    }
    return dp[ind][REM]%=mod;
}
void sol(ll test){
    cin>>n;    
    int k;cin>>k;
    val.assign(n,0);
    num.assign(n,0);
    dp.assign(n,vector<int>(k+1,-1));
    for(auto &x:val)cin>>x;
    for(auto &x:num)cin>>x;
    cout<<"Case "<<test<<": "<<OK(0,k)<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
}


