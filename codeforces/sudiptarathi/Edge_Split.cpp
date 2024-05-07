//https://codeforces.com/contest/1726/problem/D
#include<bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(),(x.end())
#define F first
#define S second
#define sz(x) (x).size()
const ll inf=1LL<<60;
const ll mod=1e9+7;
using pii=std::pair<int,int>;
using pll=std::pair<ll,ll>;
using vl=std::vector<ll>;
using vi=std::vector<int>;
using seti=std::set<int>;
using setl=std::set<ll>;
using namespace std;
void sol(int test_case);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t=1;cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}
class graph{
    public:
        vector<vector<pii>>edges;
        vector<pii>edgelist;
        vi par,depth,vis,tree_edge;
        int N,M;
        graph(int n,int m){
            N=n,M=m;
            edges.resize(n);
            vis.resize(n,false);
            par.resize(n,-1);
            depth.resize(n,0);
            edgelist.resize(m);
            tree_edge.resize(m,0);
        }
        void add(int a,int b,int i){
            a--,b--;
            edges[a].push_back({b,i});
            edges[b].push_back({a,i});
            edgelist[i]=pii(a,b);
        }
        void dfs(int source=0){
            vis[source]=true;
            for(pii child:edges[source]){
                if(vis[child.F])continue;
                par[child.F]=source;
                depth[child.F]=depth[source]+1;
                tree_edge[child.S]=1;
                dfs(child.F);
            }
        }
        void show_tree_edge(){
            cout<<"-----------------------------\n";
            for(int i=0;i<M;i++){
                if(tree_edge[i]==0){
                    cout<<1+edgelist[i].F<<" "<<1+edgelist[i].S<<endl;
                }
            }
            cout<<"-----------------------------\n";
        }
        void shuffle(){
            map<int,int>mp;
            for(int i=0;i<M;i++){
                if(tree_edge[i]==0){
                    mp[edgelist[i].F]++;
                    mp[edgelist[i].S]++;
                }
            }
            if(sz(mp)==3){
                int mn=N+1,mx=0;
                for(auto x:mp){
                    mn=min(mn,x.S);
                    mx=max(mx,x.S);
                }
                if(mn==mx and mn==2){
                    vector<pii>temp;
                    for(auto x:mp){
                        temp.push_back({depth[x.first],x.first});
                    }
                    sort(all(temp));
                    reverse(all(temp));
                    int U=temp[0].second;
                    int tempi,tempj;
                    for(pii x:edges[U]){
                        if(tree_edge[x.second]==0){
                            tempi=x.second;
                        }else if(x.first==par[U]){
                            tempj=x.second;
                        }
                    }
                    tree_edge[tempi]=1;
                    tree_edge[tempj]=0;
                }
            }
        }
        void ans(){
            for(int i=0;i<M;i++){
                cout<<tree_edge[i];
            }
            cout<<endl;
        }
};
void sol(int test_case){
    int a,b,n,m;cin>>n>>m;
    graph G(n,m);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        G.add(a,b,i);
    }
    G.dfs();
    G.shuffle();
    G.ans();
}
