#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mkp make_pair
#define pb push_back
#define pf push_front
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
#define fst first
#define scnd second
#define IN cin
#define out cout
#define all(s) (s).begin(),(s.end())
#define sz(x) (ll)(x).size();
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define FORd(i,a,b) for(int i=a;i>=b;i--)
#define F0Rd(i,a) for(int i=a;i>=0;i--)
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
typedef priority_queue<pl> pql;
typedef set<pl> stp;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<string> vs;
void sol(){
    ll n,x;IN>>n>>x;
    vl v(x+1,0);
    F0R(i,n){
        ll a;cin>>a;
        v[a]++;
    }

    FOR(i,1,x){
        if(v[i]%(i+1)==0){
            v[i+1]+=(v[i]/(i+1));
            v[i]=0;
        }
    }
    FOR(i,1,x){
        if(v[i]){
            out<<"No"<<endl;return;
        }
    }
    out<<"Yes"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;
    for(ll i=1;i<=t;i++){
        sol();
    }
    return 0;
}
