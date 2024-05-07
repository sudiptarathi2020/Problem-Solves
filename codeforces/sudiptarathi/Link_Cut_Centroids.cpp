//https://codeforces.com/problemset/problem/1406/C
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
template<class T>
struct SZ{
    T n;
    T ans;
    vector<vector<T>>edges;
    vector<bool>vis;
    vector<T>Sz;
    vector<T>parentt;
    vector<pair<T,T>>mx;
    SZ(){}
    SZ(T _n){
        ans=-1;
        this->n=_n;
        edges.resize(n);
        parentt.resize(n);
        vis.resize(n);
        Sz.resize(n);
        mx.resize(n);
    }
    void add(T a,T b){
        edges[a].pb(b);
        edges[b].pb(a);
    }
    void DFS(T source,T parent){
        Sz[source]+=1;
        parentt[source]=parent;
        vis[source]=true;
        pair<T,T>K=mkp(-1,-1);
        for(T x:edges[source]){
            if(vis[x])continue;
            DFS(x,source);
            Sz[source]+=Sz[x];
            K=max(K,mkp(Sz[x],x));
        }
        K=max(K,mkp(n-1-Sz[source],parent));
        mx[source]=K;
    }
    void CENT(T source,T par){
        if(edges[source].size()==1){
            ans=source;
            return;
        }
        for(T x:edges[source]){
            if(x==par)continue;
            CENT(x,source);
        }
    }
    pair<pair<T,T>,pair<T,T>> run(){
        DFS(1,0);
        vector<array<int,3>>mxx;
        for(int i=1;i<n;i++){
            mxx.pb({mx[i].first,i,mx[i].second});
        }
        sort(all(mxx));
        if(mxx[0][0]==mxx[1][0]){
            int F=mxx[0][1],FF=mxx[1][1];
            if(parentt[F]!=FF)swap(F,FF);
            CENT(F,FF);
            return mkp(mkp(ans,parentt[ans]),mkp(ans,FF));
        }else{
            return mkp(mkp(mxx[0][1],edges[mxx[0][1]][0]),mkp(mxx[0][1],edges[mxx[0][1]][0]));
        }
         return mkp(mkp(-1,-1),mkp(-1,-1));
    }
};
void sol(ll test){
    int n;cin>>n;
    SZ<int>S(n+1); 
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        S.add(a,b);
    }
    pair<pair<int,int>,pair<int,int>>ans=S.run();
    cout<<ans.first.first<<" "<<ans.first.second<<"\n"<<ans.second.first<<" "<<ans.second.second<<endl;
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


