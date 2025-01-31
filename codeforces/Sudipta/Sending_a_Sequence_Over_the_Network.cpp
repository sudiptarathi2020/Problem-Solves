#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define IN cin
#define out cout
#define mkp make_pair
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
#define rev reverse
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
const ll mod=1e9+7;
void sol(ll test);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}
void sol(ll test){
    ll n;cin>>n;
    vl v(n+1),dp(n+1);
    FOR(i,1,n+1){
        IN>>v[i];
    }
    dp[0]=1;
    FOR(i,1,n+1){
        if(i-(v[i]+1)>=0 and dp[i-v[i]-1]){
            dp[i]=1;
        }
        if(i+v[i]<=n and dp[i-1]){
            dp[i+v[i]]=1;
        }
    }
    if(dp.back()){
        out<<"yEs"<<endl;
        return;
    }
    out<<"nO"<<endl;
}
