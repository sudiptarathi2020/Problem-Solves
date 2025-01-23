
#include<bits/stdc++.h>
#include <math.h>
#include <utility>
#define ll long long
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
int timer;
vector<pair<int,int>>euler;
vector<int>shuru;
vector<int>Depth;
vector<vector<int>>edges;
void dfs(int source,int parent,int depth=0){
    shuru[source]=sz(euler);
    Depth[source]=depth;
    euler.pb(make_pair(depth,source));
    for(int x:edges[source]){
        if(x==parent)continue;
        dfs(x,source,depth+1);
        euler.pb(make_pair(depth,source));
    }
}
template<typename T>struct rmq{
    const int K=20;
    vector<int>lg;
    int N;
    vector<vector<T>>st;
    rmq(){}
    rmq(vector<T>S){
        N=S.size();
        lg.resize(N+1);
        lg[1]=0;
        for(int i=2;i<=N;i++){
            lg[i]=lg[i/2]+1;
        }
        st.resize(K+1,vector<T>(N+1));
        for(int i=0;i<=N;i++){
            st[0][i]=S[i];
        }
        for(int i=1;i<=K;i++){
            for(int j=0;j+(1<<i)<=N;j++){
                st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
            }
        }
    }
    T get(int L,int R){
        int i=lg[R-L+1];
        return min(st[i][L],st[i][R-(1<<i)+1]);
    }
};
void sol(int test_case){
    int n,q;cin>>n>>q;
    edges.resize(n+1);
    shuru.resize(n+1);
    Depth.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    dfs(1,-1);
    rmq<pair<int,int>>r(euler);
    while(q--){
        int a,b;cin>>a>>b;
        int shu=shuru[a],she=shuru[b];
        if(shu>she)swap(shu,she);
        pair<int,int> x=r.get(shu,she);
        cout<<Depth[a]+Depth[b]-2*(Depth[x.second])<<"\n";
    }
}
