//https://codeforces.com/problemset/problem/1690/F
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
struct dfs{
    ll n;
    vector<vector<ll>>edges;
    vector<bool>vis;
    ll timer=0;
    vector<pair<char,ll>>order;
    vector<vector<ll>>kar;
    vector<char>arr;
    dfs(){}
    void init(ll _n){
        this->n=_n+1;
        kar.resize(26);
        edges.resize(n);
        arr.resize(n);
        vis.resize(n);
    }
    void add(ll a,ll b){
        edges[a].pb(b);
    }
    void DFS(ll source){
        vis[source]=true;
        kar[arr[source]-'a'].pb(timer);
        timer++;
        for(ll x:edges[source]){
            if(vis[x])continue;
            DFS(x);
        }
    }
    void D(ll source){
        timer=0;
        DFS(source);
    }
};
dfs d;
ll lcm(ll a,ll b){
    return a*b/__gcd(a,b);
}
void sol(ll test){
    ll n;cin>>n;
    string s;cin>>s;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        arr[i]--;
    }
    vector<bool>vis(n);
    ll an=1;
    for(ll i=0;i<n;i++){
        if(!vis[i]){
            string k;
            ll v=i;
            k+=s[i];
            vis[v]=true;
            v=arr[v];
            while(v!=i){
                vis[v]=true;
                k+=s[v];
                v=arr[v];
            }
            string p=k+k;
            ll des=-1;
            for(ll j=1;j<(ll)k.size()+1;j++){
                bool t=true;
                for(ll L=0;L<(ll)k.size();L++){
                    t&=p[j+L]==k[L];
                }
                if(t){
                    des=j;
                    break;
                }
            }
            an=lcm(an,des);//des;
        }
    }
    cout<<an<<endl;
    return; 
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
