
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define ull unsigned long long
#define all(x) (x).begin(),(x.end())
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define sz(x) (x).size()
const ll inf=1LL<<60;
const ll mod=1e9+7;
using pii=std::pair<int,int>;
using pll=std::pair<ll,ll>;
using vl=std::vector<ll>;
using vi=std::vector<int>;
using seti=std::set<int>;
using setl=std::set<ll>;
using pq=std::priority_queue<ll>;
using namespace std;
void sol(int test_case);
vector<vector<int>>edges;
vector<int>sz;
void dfs(int source,int parent){
    sz[source]=1;
    for(int x:edges[source]){
        if(x==parent)continue;
        dfs(x,source);
        sz[source]+=sz[x];
    }
}
int centoid(int source,int parent){
    for(int x:edges[source]){
        if(x==parent)continue;
        if(sz[x]>(sz[1]>>1)){
            return centoid(x,source);
        }
    }
    return source;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
 
    int t=1;
//    cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}
void sol(int test_case){
    int n;cin>>n;
    edges.resize(n+1);
    sz.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        edges[a].pb(b),edges[b].pb(a);
    }
    dfs(1,1);
    cout<<centoid(1,1)<<endl;
}
