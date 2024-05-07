//https://codeforces.com/problemset/problem/653/E
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
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define FORd(i,a,b) for(int i=a;i>=b;i--)
#define F0Rd(i,a) for(int i=a;i>=0;i--)
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
st kt;
set<pair<ll,ll>> pst;
bool is_ok(ll a,ll b){
    if(a>b)swap(a,b);
    return pst.find(mkp(a,b))==pst.end();
}
void dfs(ll source){
    vl ans;
    for(ll x:kt){
        if(is_ok(source,x)){
            ans.pb(x);
        }
    }
    for(ll x:ans){
        kt.erase(kt.find(x));
    }
    for(ll x:ans){
        dfs(x);
    }
}
void sol(ll test){
    ll a,b,n,m,k;cin>>n>>m>>k;
    for(ll i=2;i<=n;i++){
        kt.insert(i);
    }
    ll allowed=n-1;
    for(ll i=1;i<=m;i++){
        cin>>a>>b;
        if(a>b)swap(a,b);
        if(a==1)allowed--;
        pst.insert(mkp(a,b));
    }
    if(allowed<k){
        cout<<"impossible"<<endl;
        return;
    }
    ll cnt=0;
    for(ll i=2;i<=n;i++){
        if(is_ok(1,i) and kt.find(i)!=kt.end()){
            cnt++;
            dfs(i);
        }
    }
    if(kt.size() or cnt>k){
        cout<<"impossible"<<endl;
        return;
    }
    cout<<"possible"<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;//cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
}


