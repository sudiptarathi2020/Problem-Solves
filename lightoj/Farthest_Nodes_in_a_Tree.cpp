
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define endl '\n'
#define ub upper_bound
#define mkp make_pair
#define lb lower_bound
#define fst first
#define scnd second
#define all(s) (s).begin(),(s.end())
#define sz(x) (ll)(x).size();
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define f0rd(i,a) for(int i=a;i>=0;i--)
using namespace std;
const ll inf=LLONG_MAX;
const ll ninf=LLONG_MIN;
typedef pair<ll,ll> pl;
typedef set<ll> st;
typedef queue<ll> ql;
typedef queue<pl> qpl;
typedef stack<ll> stk;
typedef stack<pl> stkp;
typedef priority_queue<ll> pq;
typedef priority_queue<pl> pql;
typedef set<pl> stp;
typedef vector<ll> vl;
typedef vector<bool>vbool;
typedef vector<pl> vpl;
typedef vector<string> vs;
const int N=3e4+10;
vpl v[N];
vl dist(N);
void sol(int test){
    F0R(i,N){
        v[i].clear();
        dist[i]=0;
    }
    ll n;cin>>n;
    F0R(i,n-1){
        ll a,b,c;cin>>a>>b>>c;
        v[a].pb(mkp(b,c));
        v[b].pb(mkp(a,c));
    }
    vbool vis(n,false); 
    ql q;
    q.push(0);
    dist[0]=0;
    while(q.size()){
        ll x=q.front();
        q.pop();
        if(vis[x])continue;
        vis[x]=true;
        for(auto u:v[x]){
            if(vis[u.first])continue;
            dist[u.first]=u.second+dist[x];
            q.push(u.first);
        }
    }
    vis.assign(n,false);
    ll source;
    ll d=0;
    F0R(i,n){
        if(dist[i]>=d){
            source=i;
            d=dist[i];
        }
    }
    dist.assign(n,0);    
    q.push(source);
    dist[source]=0;
    while(q.size()){
        ll x=q.front();
        q.pop();
        if(vis[x])continue;
        vis[x]=true;
        for(auto u:v[x]){
            if(vis[u.first])continue;
            dist[u.first]=u.second+dist[x];
            q.push(u.first);
        }
    }
    sort(all(dist),greater<ll>());
    cout<<"Case "<<test<<": "<<dist.front()<<endl;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;cin>>t;
    for(int i=1;i<=t;i++)sol(i);
    return 0;
}
