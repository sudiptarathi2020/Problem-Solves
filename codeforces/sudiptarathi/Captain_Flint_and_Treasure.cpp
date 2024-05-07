//https://codeforces.com/problemset/problem/1388/D
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) (x).begin(),(x.end())
#define endl "\n"
#define F first
#define S second
#define sz(x) (x).size()
const ll inf=1LL<<60;
const ll mod=1e9+7;
using pii=std::pair<ll,ll>;
using pll=std::pair<ll,ll>;
using vl=std::vector<ll>;
using vi=std::vector<ll>;
using seti=std::set<ll>;
using setl=std::set<ll>;
using namespace std;
void sol(ll test_case);
int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll t=1;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}
class solve{
    private:
        vector<vi>edges;
        vector<pii>val_with_depth;
        vector<bool>vis;
        vi depth,temp,par,val,sources;
        ll n,ans;
void dfs(ll source){
            val_with_depth.pb({depth[source],source});
            for(ll x:edges[source]){
                par[x]=source;
                depth[x]=depth[source]+1;
                dfs(x);
            }
        }
    public:
        solve(){}
        void rs(ll _n){
            ans=0;
            this->n=_n;
            sources.clear();
            depth.resize(n);
            par.resize(n);
            val.resize(n);
            vis.resize(n);
            edges.resize(n);
        }
        void INPUT(){
            for(auto &x:val)cin>>x;
            for(ll i=0;i<n;i++){
                ll a;cin>>a;
                if(a==-1){
                    sources.pb(i);
                }else{
                    edges[a-1].pb(i);
                }
            }
        }
        void DFS(){
            for(ll x:sources){
                val_with_depth.clear();
                par[x]=-1;
                dfs(x);
                sort(all(val_with_depth));
                reverse(all(val_with_depth));
                for(auto x:val_with_depth){
                    if(val[x.S]<0)continue;
                    if(vis[x.S])continue;
                    vis[x.S]=true;
                    temp.pb(x.S+1);
                    ans+=val[x.S];
                    if(par[x.S]!=-1){
                        val[par[x.S]]+=val[x.S];
                    }
                }
                sort(all(val_with_depth));
                for(auto x:val_with_depth){
                    if(vis[x.S])continue;
                    ans+=val[x.S];
                    temp.pb(x.S+1);
                    vis[x.S]=true;
                }
            }
            cout<<ans<<endl;
            for(ll x:temp){
                cout<<x<<" ";
            }
            cout<<endl;
        }
};solve S;
void sol(ll test_case){
    ll n;cin>>n;
    S.rs(n);
    S.INPUT();
    S.DFS();
}
