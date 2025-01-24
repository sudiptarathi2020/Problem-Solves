
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
struct BIT {
    vector<ll> bit;  // binary indexed tree
    ll n;

    BIT(ll n) {
        this->n = n;
        bit.assign(n, 0);
    }
    ll sum(ll r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret%mod;
    }

    ll sum(ll l, ll r) {
        return (sum(r) - sum(l - 1))%mod;
    }

    void add(ll idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta%mod,bit[idx]%=mod;
        
    }
};
void sol(int test){
    ll n;cin>>n; 
    vpl v(n);
    F0R(i,n){
        IN>>v[i].fst;
        v[i].scnd=i;
    }
    BIT bit(n);
    sort(all(v),[&](pl a,pl b){
            if(a.fst!=b.fst){
            return a.fst<b.fst;
            }
            return a.scnd>b.scnd;
            });
    F0R(i,n){
        ll x=bit.sum(0,v[i].scnd-1);
        bit.add(v[i].scnd,x+1);
    }
    out<<"Case "<<test<<": "<<bit.sum(0,n-1)%mod<<endl;
    return; 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}

