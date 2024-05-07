//https://codeforces.com/problemset/problem/1592/C
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
struct BP{
    ll n; 
    vector<vector<ll>>edges;
    vector<ll>sub;
    vector<int>order;
    vector<ll>in,out;
    vector<bool>vis;
    vector<ll>val;
    vector<ll>level;
    set<ll>Pt;
    ll timer;
    ll K;
    ll x;
    vector<ll>par;
    BP(){}
    BP(ll _n){
        this->n=_n;
        timer=0;
        x=0;
        edges.resize(n,vector<ll>());
        vis.resize(n);
        Pt.clear();
        in.resize(n);
        out.resize(n);
        level.resize(n);
        sub.resize(n);
        par.resize(n);
        val.resize(n);
    }
    void add(ll a,ll b){
        edges[a].pb(b);
        edges[b].pb(a);
    }
    void dfs(ll source,ll parent){
        par[source]=parent; 
        in[source]=timer;
        timer++;
        level[source]=level[parent]+1;
        sub[source]=val[source];
        for(ll x:edges[source]){
            if(x==parent)continue;
            dfs(x,source);
            sub[source]^=sub[x];
        }
        out[source]=timer;
        timer++;
        order.pb(source);
    }            
    bool ase(ll source){
        return Pt.count(source);
    }
    void DFS(ll source,ll parent){
        sub[source]=val[source];
        for(ll x:edges[source]){
            if(x==parent or ase(x)){
                continue;
            }
            DFS(x,source);
            sub[source]^=sub[x];
        }
    }
    string run(){
        dfs(0,0);
        ll hoise=-1;
        bool paisi=false;
        for(int i:order){
            if(sub[i]==x){
                hoise=i; 
                paisi=true;
                break;
            }
        }
        if(paisi){
            Pt.insert(hoise);
            for(int i=0;i<n;i++){
                if(in[hoise]<=in[i] and out[i]<=out[hoise]){
                    Pt.insert(i);
                }
            }
            sub.assign(n,0);
            reverse(all(order));
            for(ll x:order){
                if(!ase(x)){
                    DFS(x,x);
                    break;
                }
            }
            for(int i=0;i<n;i++){
                if(!ase(i)){
                    if(sub[i]==x){
                        if(K!=2){
                            return "YES";
                        }
                    }
                }
            }
        }else{
            return "NO";
        }
        return "NO";
    }
};
void sol(ll test){
    ll n,a,b;IN>>n;
    ll k;IN>>k;
    BP S(n);
    S.K=k;
    ll C=0;
    F0R(i,n){
        IN>>S.val[i];
        C^=S.val[i];
    }
    F0R(i,n-1){
        IN>>a>>b;
        a--,b--;
        S.add(a,b);
    }
    if(!C){
        printf("YES\n");
        return;
    }else{
        if(k==2){
            cout<<"NO\n";
            return;
        }
        S.x=C;
        string ans=S.run();
        cout<<ans<<endl;
    }
}
int main(){
    ll t;cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
}


