//https://codeforces.com/problemset/problem/1793/D
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
#define rall(s) (s).rbegin(),(s.rend())
#define sz(x) (ll)(x).size();
#define FOR(i,a,b) for(ll i=a;i<(b);i++)
#define F0R(i,a) for(ll i=0;i<(a);i++)
#define FORd(i,a,b) for(ll i=a;i>=b;i--)
#define F0Rd(i,a) for(ll i=a;i>=0;i--)
using namespace std;
const ll inf=LLONG_MAX;
const ll ninf=LLONG_MIN;
const ll N=2e5;
const ll mod=1e9+7;
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
void sol(ll test){
    ll n;cin>>n;
    vl P(n+1),Q(n+1);
    ll x;
    for(ll i=1;i<=n;i++){
        cin>>x;
        P[x]=i;
    }
    for(ll i=1;i<=n;i++){
        cin>>x;
        Q[x]=i;
    }
    ll L=min(P[1],Q[1]);
    ll Lcnt=L-1;
    ll result=(Lcnt*(Lcnt+1))>>1;
    ll R=max(P[1],Q[1]);
    ll Rcnt=n-R;
    result+=(Rcnt*(Rcnt+1))>>1;
    ll Mcnt=(R-L-1);
    result+=(Mcnt*(Mcnt+1))>>1;
    L=n,R=-1;
    for(ll mex=2;mex<=n;mex++){
        L=min({L,P[mex-1],Q[mex-1]}); 
        R=max({R,P[mex-1],Q[mex-1]});
        if(L<=P[mex] and P[mex]<=R)continue;
        if(L<=Q[mex] and Q[mex]<=R)continue;
        ll start=1,end=n;
        if(P[mex]<L){
            start=max(start,P[mex]+1);
        }
        if(Q[mex]<L){
            start=max(start,Q[mex]+1);
        }
        if(P[mex]>R){
            end=min(end,P[mex]-1);
        }
        if(Q[mex]>R){
            end=min(end,Q[mex]-1);
        }
        ll kt=L-start+1;
        ll pt=end-R+1;
        result+=kt*pt;
    }
    result++;
    cout<<result<<endl;
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}

