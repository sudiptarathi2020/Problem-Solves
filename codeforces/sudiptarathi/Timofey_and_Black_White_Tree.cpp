//https://codeforces.com/problemset/problem/1790/F
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
struct LCA{
    int n,timer;
    int lg;
    vector<vector<int>>edges,par;
    vector<int>depth,in,out;
    vector<bool>vis;
    LCA(){}
    LCA(int _n){
        this->n=_n;
        this->timer=0;
        this->lg=ceil(log2(n));
        par.assign(n+1,vector<int>(lg+1));
        edges.assign(n+1,vector<int>());
        depth.assign(n+1,-1);
        vis.assign(n+1,false);
        in.assign(n+1,-1);
        out.assign(n+1,-1);
    }
    void INIT(int _n){
        this->n=_n;
        this->timer=0;
        this->lg=ceil(log2(n));
        par.assign(n+1,vector<int>(lg+1));
        edges.assign(n+1,vector<int>());
        depth.assign(n+1,-1);
        vis.assign(n+1,false);
        in.assign(n+1,-1);
        out.assign(n+1,-1);
    }

    void add(int a,int b){
        edges[a].pb(b);
        edges[b].pb(a);
    }
    void DFS(int source=0,int parent=0){
        vis[source]=true;
        in[source]=timer++;
        depth[source]=depth[parent]+1;
        par[source][0]=parent;
        for(int i=1;i<=lg;i++){
            par[source][i]=par[par[source][i-1]][i-1];
        }
        for(int x:edges[source]){
            if(vis[x])continue;
            DFS(x,source);
        }
        out[source]=timer++;
    }
    bool IS(int a,int b){
        if(in[a]<=in[b] and out[a]>=out[b]){
            return true;
        }
        return false;
    }
    void init(){
        depth[0]=-1;
        DFS();
    }
    int lca(int u,int v){
        if(IS(u,v)){
            return u;
        }
        if(IS(v,u)){
            return v;
        }
        for(int i=lg;i>=0;i--){
            if(!IS(par[u][i],v)){
                u=par[u][i];
            }
        }
        return par[u][0];
    }
    int get_dist(int u,int b){
        int x=lca(u,b);
        return depth[u]+depth[b]-2*depth[x];
    }
};
LCA L;
struct centroid{
    int n;
    vector<vector<int>>edges;
    vector<bool>vis;
    vector<int>par;
    vector<int>sz;
    centroid(){}
    centroid(int _n){
        this->n=_n;
        edges.assign(n+1,vector<int>());
        vis.assign(n+1,false);
        par.assign(n+1,0);
        sz.assign(n+1,0);
    }
    void INIT(int _n){
        this->n=_n;
        edges.assign(n+1,vector<int>());
        vis.assign(n+1,false);
        par.assign(n+1,0);
        sz.assign(n+1,0);
    }
    void add(int a,int b){
        edges[a].pb(b);
        edges[b].pb(a);
    }
    void find_sz(int v,int p=-1){
        if(vis[v])return;
        sz[v]=1;
        for(int x:edges[v]){
            if(x!=p and !vis[x]){
                find_sz(x,v);
                sz[v]+=sz[x];
            }
        }
    }
    int find_cen(int v,int p,int NN){
        for(int x:edges[v]){
            if(x!=p){
                if(!vis[x] and sz[x]>NN/2){
                    return find_cen(x,v,NN);
                }
            }
        }
        return v;
    }
    void init_cen(int v=0,int p=-1){
        find_sz(v);
        int c=find_cen(v,-1,sz[v]);
        vis[c]=true;
        par[c]=p;
        for(int x:edges[c]){
            if(!vis[x]){
                init_cen(x,c);
            }
        }
    }
};
centroid C;
vector<int>best;
void update(int v){
    best[v]=0;
    int u=v;
    while(C.par[u]!=-1){
        u=C.par[u];
        best[u]=min(best[u],L.get_dist(u,v));
    }
}
int quety(int v){
    int ans=best[v];
    int u=v;
    while(C.par[u]!=-1){
        u=C.par[u];
        ans=min(ans,best[u]+L.get_dist(u,v));
    }
    return ans;
}
void sol(ll test){
    int n;cin>>n;
    L.INIT(n);
    C.INIT(n);
    best.assign(n+1,n);
    int p;cin>>p,p--;
    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
        arr[i]--;
    }
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        L.add(a,b);
        C.add(a,b);
    }
    L.init();
    C.init_cen();
    update(p);
    int ans=n;
    for(int i=0;i<n-1;i++){
        ans=min(ans,quety(arr[i])); 
        cout<<ans<<" ";
        update(arr[i]);
    }
    cout<<endl;
    return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}

