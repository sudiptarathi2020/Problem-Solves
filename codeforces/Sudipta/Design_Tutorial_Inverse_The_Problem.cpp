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
#define aint(s) (s).begin(),(s.end())
#define sz(x) (int)(x).size();
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define FORd(i,a,b) for(int i=a;i>=b;i--)
#define F0Rd(i,a) for(int i=a;i>=0;i--)
using namespace std;
const int inf=INT_MAX;
const int ninf=INT_MIN;
const int N=2e5;
const int mod=1e9+7;
typedef pair<int,int> pl;
typedef set<int> st;
typedef queue<int> ql;
typedef queue<pl> qpl;
typedef stack<int> stk;
typedef stack<pl> stkp;
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int>> rpq;
typedef priority_queue<pl> pql;
typedef priority_queue<pl,vector<pl>,greater<pl>> rpql;
typedef set<pl> stp;
typedef vector<int> vl;
typedef set<int,greater<int>> rst;
typedef set<pl,greater<pl>> rstp;
typedef vector<pl> vpl;
typedef vector<string> vs;
struct dsu{
    int n;
    vl parent,Sz;
    dsu(){}
    dsu(int nn){
        this->n=nn;
        parent.resize(nn+1);
        Sz.resize(nn+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            Sz[i]=1;
        }
    }
    int find(int a){
        if(parent[a]==a){
            return parent[a];
        }else{
            return parent[a]=find(parent[a]);
        }
    }
    void unify(int a,int b){
        a=find(a),b=find(b);
        if(a==b){
            return ;
        }else{
            if(Sz[a]<Sz[b]){
                swap(a,b);
            }
            parent[b]=a;
            Sz[a]+=Sz[b];
        }
    }
};
struct lca{
    vl fst,euler,dist,level,vis,segtree;
    vector<vector<pair<int,int>>>adj;
    int n;
    lca(){}
    lca(int nn){
        this->n=nn;
        fst.resize(n+1);
        euler.reserve(2*n+1);
        adj.resize(n+1);
        dist.resize(n+1);
        level.resize(n+1);
        vis.assign(n+1,false);
    }
    void add(int a,int b,int c){
        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }
    void build(){
        dfs(0,0,0);
        int mid=(int)euler.size();
        segtree.assign(4*mid,0);
        build(1,0,mid-1);
    }
    void build(int node,int stt,int en){
        if(stt==en){
            segtree[node]=euler[stt];
            return;
        }
        int mid=(stt+en)>>1;
        build(node<<1,stt,mid);
        build((node<<1)|1,mid+1,en);
        int l=segtree[node<<1],r=segtree[(node<<1)|1];
        segtree[node]=(level[l]<level[r])?l:r;
    }
    int q(int node,int stt,int en,int x,int y){
        if(stt>y or en<x){
            return -1;
        }
        if(stt>=x and en<=y){
            return segtree[node];
        }
        int mid=(stt+en)/2;
        int left=q(node<<1,stt,mid,x,y);
        int right=q((node<<1)|1,mid+1,en,x,y);
        if(left==-1)return right;
        if(right==-1)return left;
        return (level[left]<level[right])?left:right;
    }
    void dfs(int node,int height,int d){
        vis[node]=true;
        level[node]=height;
        dist[node]=d;
        first[node]=(int)euler.size();
        euler.push_back(node);
        for(auto to:adj[node]){
            if(!vis[to.first]){
                dfs(to.first,height+1,d+to.second);
                euler.push_back(node);
            }
        }
    }
    int lc(int u,int v){
        int left=fst[u],right=fst[v];
        if(left>right){
            swap(left,right);
        }
        return q(1,0,(int)euler.size()-1,left,right);
    }
};
void sol(int test){
    int n;cin>>n;
    vector<vl>arr(n,vl(n));
    bool hoise=true;
    vector<pair<int,pair<int,int>>>v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j]; 
            if(i==j and arr[i][j]!=0){
                hoise=false;
            }
            if(i!=j and arr[i][j]==0){
				hoise=false;
			}
            if(i==j)continue;
            v.pb(mkp(arr[i][j],mkp(i,j)));
            v.pb(mkp(arr[i][j],mkp(j,i)));
        }
    }
    if(!hoise){
        cout<<"NO\n";return;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i][j]!=arr[j][i]){
                cout<<"NO\n";return;
            }
        }
    }
    sort(aint(v));
    dsu DSU(n+1);
    lca l(n+1);
    for(auto I:v){
         if(DSU.find(I.second.first)!=DSU.find(I.second.second)){
             l.add(I.second.first,I.second.second,I.first);
             DSU.unify(I.second.first,I.second.second);
         }
    }
    l.build();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(i==j){
                continue;
            }
            int c=l.lc(i,j);
            int ans=l.dist[i]-l.dist[c]+l.dist[j]-l.dist[c];
            if(ans!=arr[i][j]){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;//cin>>t;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}
 