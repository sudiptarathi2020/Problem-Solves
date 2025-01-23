
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mkp make_pair
#define pb push_back
#define pf push_front
#define endl '\n'
#define ub upper_bound
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
typedef vector<pl> vpl;
typedef vector<string> vs;
void sol(int test){
    int n,m;cin>>n>>m;
    vpl v[n];
    F0R(i,m){
        ll a,b,c;cin>>a>>b>>c;
        v[a].pb(mkp(b,c));
        v[b].pb(mkp(a,c));
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    vl dist(n,inf);
    ll my;cin>>my;
    pq.push(mkp(0,my));
    dist[my]=0;
    vector<bool>vis(n);
    while(pq.size()){
        auto it=pq.top();
        pq.pop();
        if(vis[it.second])continue;
        vis[it.second]=true;
        for(pl x:v[it.second]){
            if(max(x.second,it.first)<dist[x.first]){
                dist[x.first]=max(x.second,it.first);   
                pq.push({mkp(dist[x.first],x.first)});
            }
        }
    }
    cout<<"Case "<<test<<": "<<endl; 
    F0R(i,n){
        if(dist[i]==inf)cout<<"Impossible"<<endl;
        else
            cout<<dist[i]<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}

