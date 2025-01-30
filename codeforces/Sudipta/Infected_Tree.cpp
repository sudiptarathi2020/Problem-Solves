#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define mkp make_pair
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
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
void sol(){
    ll n;cin>>n;
    vector<ll>v[n+1];
    vector<ll>vv[n+1];
    F0R(i,n-1){
        ll a,b;cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    ll source=1;
    vector<bool>vis(n+1);
    vector<ll>dist(n+1);
    queue<ll>q;
    dist[source]=0;
    q.push(source);
    vector<ll>path(n+1);
    path[source]=-1;
    while(q.size()){
        ll x=q.front();q.pop();
        if(vis[x])continue;
        vis[x]=true;
        for(ll u:v[x]){
            if(not vis[u]){
                vv[x].pb(u);
                dist[u]=1+dist[x];
                path[u]=x;
                q.push(u);
            }
        }
    }
    if(n==2){
        cout<<0<<endl;
        return;
    }
    vector<array<ll,3>> ans;
    for(ll i=1;i<=n;i++){
        ans.pb({dist[i],(ll)vv[i].size(),i});;
    }
    sort(all(ans));
    //for(array<ll,3>x :ans){
		//cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
	//}
    ll dest;
    for(array<ll,3> x:ans){
        if(vv[x[2]].size()<2){
            dest=x[2];
            break;
        }
    }
    //cout<<dest<<endl;
    //for(array<ll,3>x :ans){
		//cout<<x[2]<<" "<<path[x[2]]<<endl;
	//}
    vl kt;
    while(dest!=-1){
        kt.push_back(dest);
     //   cout<<dest<<" ";
        dest=path[dest];
    }
    vis.assign(n+1,1);
    reverse(all(kt));
    for(ll x:kt){
        vis[x]=0;
        for(ll j:v[x]){
            vis[j]=0;
        }
    }
    ll jjj=0;
    for(ll i=1;i<=n;i++){
        jjj+=vis[i];
    }
    cout<<jjj<<endl;
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
