
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
struct ART{
    vector<vector<int>>adj;
    int timer;
    set<pair<int,int>>ans;
    vector<bool>vis;
    vector<int>tin,low;
    int n;
    ART(){}
    ART(int _n){
        this->n=_n;
        timer=0;
        adj.resize(n+1);
        vis.resize(n+1);
        tin.resize(n+1);
        low.resize(n+1);
    }
    void add(int a,int b){
        adj[a].pb(b);
        adj[b].pb(a);
    }
    void IS(int a,int b){
        if(a>b)swap(a,b);
        ans.insert(mkp(a,b));
    }
    void dfs(int source,int p=-1){
        vis[source]=true;
        tin[source]=low[source]=timer++; 
        for(int to:adj[source]){
            if(to==p)continue;
            if(vis[to]){
                low[source]=min(low[source],tin[to]);
            }else{
                dfs(to,source);
                low[source]=min(low[source],low[to]);
                if(low[to]>tin[source]){
                    IS(to,source);
                }
            }
        }
    }
    void get_ans(){
        cout<<(int)ans.size()<<" critical links"<<endl;
        for(auto to:ans){
            cout<<to.first<<" - "<<to.second<<endl;
        }
    }
};
void sol(ll test){
    int a,b,n;cin>>n;
    ART A(n);
    for(int i=1;i<=n;i++){
        char f,s;
        int c;
        cin>>a>>f>>b>>s;
        for(int j=0;j<b;j++){
            cin>>c;
            A.add(a,c);
        }
    }
    for(int i=0;i<n;i++){
        if(not A.vis[i]){
            A.dfs(i);
        }
    }
    cout<<"Case "<<test<<": \n";
    A.get_ans();
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
}


