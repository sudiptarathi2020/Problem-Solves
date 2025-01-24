
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
struct graph{
    int n;
    vector<vector<int>>adj;
    map<pair<int,int>,int>dist;
    vector<int>MD; 
    vector<int>D;
    vector<bool>vis;
    graph(){}
    graph(int _n){
        this->n=_n;
        D.resize(n+1);
        vis.resize(n+1);
        MD.resize(n+1);
        adj.resize(n+1);
    }
    void add(int u,int v,int w){
        adj[u].pb(v);
        adj[v].pb(u);
        dist[mkp(u,v)]=w;
        dist[mkp(v,u)]=w;
    }
    void dfs(int source,int parent){
        D[source]=D[parent]+dist[mkp(source,parent)]; 
        MD[source]=max(MD[source],D[source]);
        vis[source]=true;
        for(int u:adj[source]){
            if(vis[u] or u==parent)continue;
            dfs(u,source);
        }
    }
    int node(){
        int mx=INT_MIN;
        int Node=-1;
        for(int i=0;i<n;i++){
            if(D[i]>mx){
                mx=D[i];
                Node=i;
            }
        }
        D.assign(n+1,0);
        vis.assign(n+1,0);
        return Node;
    }
};
void sol(ll test){
    int a,b,c,n;cin>>n; 
    graph G(n);
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        G.add(a,b,c);
    }
    G.dfs(0,0);
    int Node=G.node();
    G.dfs(Node,Node);
    int NNode=G.node();
    G.dfs(NNode,NNode);
    cout<<"Case "<<test<<": \n";
    for(int i=0;i<n;i++){
        cout<<G.MD[i]<<endl;
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
}


