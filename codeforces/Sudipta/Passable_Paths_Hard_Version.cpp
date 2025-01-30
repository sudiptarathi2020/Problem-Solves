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
const ll N=1e5+10;
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
vector<int>v[N+1];
vector<int>frst(N+1);
vector<int>height(N+1);
vector<bool>vis(N+1);
vector<int>adj;
struct m{
    vector<int>level,occur,euler,segtree;
    vector<bool>vis;
    vector<vector<int>>adj;
    int n;
    m(){}
    m(int n){
        this->n=n;
        level.resize(n+1);
        occur.resize(n+1);
        euler.reserve(2*n+1);
        vis.resize(n+1);  
        adj.resize(n+1);
    }
    void add(int a,int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void build(){
        dfs(1,0);
        int m=(int)euler.size();
        segtree.assign(4*m,0);
        build(1,0,m-1);
    }
    void build(int node,int st,int en){
        if(st==en){
            segtree[node]=euler[st];
            return;
        }
        int mid=(st+en)>>1;
        build(node<<1,st,mid);
        build((node<<1)|1,mid+1,en);
        int l=segtree[node<<1],r=segtree[(node<<1)|1];
        segtree[node]=(level[l]<level[r])?l:r;
    }
    int q(int node,int st,int en,int x,int y){
        if(st>y or en<x){
            return -1;
        }
        if(st>=x and en<=y){
            return segtree[node];
        }
        int mid=(st+en)>>1;
        int left=q(node<<1,st,mid,x,y);
        int right=q((node<<1)|1,mid+1,en,x,y);
        if(left==-1)return right;
        if(right==-1)return left;
        return (level[left]<level[right])?left:right;
    }
    int lca(int a,int b){
        int left=occur[a];
        int right=occur[b];
        if(left>right){
            swap(left,right);
        }
        return q(1,0,(int)euler.size()-1,left,right);
    }
    void dfs(int source,int height){
        level[source]=height;
        occur[source]=(int)euler.size();
        vis[source]=true;
        euler.push_back(source);
        for(int x:adj[source]){
            if(!vis[x]){
                dfs(x,height+1);
                euler.push_back(source);
            }
        }
    }
};
void sol(ll test){
    int n;cin>>n;
    m l(n);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        l.add(a,b);
    }
    l.build();
    int q;cin>>q;
    while(q--){
        int nn;cin>>nn;
        vector<int>v(nn);
        for(int i=0;i<nn;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end(),[&](int a,int b){
                return l.level[a]>l.level[b];
                });
        vector<bool>vis(nn+1);
        for(int i=0;i<nn;i++){
            if(l.lca(v[0],v[i])==v[i]){
                vis[i]=true;
            }
        }
        int check=0;
        while(check<nn and vis[check]==true){
            check++;
        }
        if(check==nn){
            cout<<"YES\n";
            continue;
        }
        for(int i=check;i<nn;i++){
            if(l.lca(v[check],v[i])==v[i]){
                vis[i]=true;
            }
        }
        bool paisi=true;
        for(int i=0;i<nn;i++){
            paisi &=vis[i];
        }
        if(!paisi){
            cout<<"NO\n";
            continue;
        }
        paisi &=l.level[l.lca(v[0],v[check])]<=l.level[v.back()];
        if(paisi){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
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
 
