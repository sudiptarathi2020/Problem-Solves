//https://codeforces.com/problemset/problem/1857/G
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
const ll mod=0x3B800001LL;
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

template<typename T>struct DSU{
    T n;
    vector<T>par,Sz;
    DSU(){}
    DSU(T _n){
        this->n=_n+1;
        par.resize(n);
        iota(all(par),0);
        Sz.resize(n,1);
    }
    T find(T a){
        if(par[a]==a)return a;
        return par[a]=find(par[a]);
    }
    void add(T a,T b){
        a=find(a),b=find(b);
        if(a==b)return;
        if(Sz[a]<Sz[b]){
            swap(a,b);
        }
        par[b]=a;
        Sz[a]+=Sz[b];
    }
    bool same(T a,T b){
        return find(a)==find(b);
    }
    T SZ(T a){
        return Sz[find(a)];
    }
};
template<typename T>
T binexpo(T A,T B){
    T ans=1;
    for(ll i=0;i<64;i++){
        if(B<(1LL<<i))break;
        if(B&(1LL<<i)){
            ans*=A;
            ans%=mod;
        }
        A*=A;
        A%=mod;
    }
    return ans%mod;
}
void sol(ll test){
    ll n,s;IN>>n>>s;
    DSU<ll>D(n);
    vector<array<ll,3>>V(n-1);
    for(auto &v:V){
        IN>>v[0]>>v[1]>>v[2]; 
    }
    sort(all(V),[](auto A,auto B){return A[2]<B[2];});
    ll ans=1;
    for(auto v:V){
        ll F=D.SZ(v[0]); 
        ll S=D.SZ(v[1]);
        ans*=binexpo<ll>(s-v[2]+1LL,F*S-1LL);
        ans%=mod;
        D.add(v[0],v[1]);
    }
    out<<ans<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    F0R(i,t){
        sol(i);
    }
}
