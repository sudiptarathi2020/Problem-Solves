
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
void sol(ll test){
    ll n;cin>>n;
    vector<ll>v[n+1]; 
    vector<vector<ll>>cost(n+1,vector<ll>(n+1));
    vector<bool>vis(n+1);
    F0R(i,n){
        ll a,b,c;cin>>a>>b>>c;;
        cost[a][b]=c;
        cost[b][a]=(-1)*c;
        v[a].pb(b);
        v[b].pb(a);
    }
    ll source=1;
    stack<ll>stk;
    stk.push(source);
    vl ans;
    while(stk.size()){
        ll vv=stk.top();
        stk.pop();
        if(vis[vv])continue;
        vis[vv]=true;
        ans.pb(vv);
        for(ll u:v[vv]){
            stk.push(u);
        }
    }
    ans.pb(ans.front());
    vl ans1=ans;
    reverse(all(ans1));
    ll costt=0;
    for(int i=0;i<n;i++){
        if(cost[ans[i]][ans[i+1]]<0){
            costt+=(-1)*cost[ans[i]][ans[i+1]];
        }
    }
    ll costt1=0;
    for(int i=0;i<n;i++){
        if(cost[ans1[i]][ans1[i+1]]<0){
            costt1+=(-1)*cost[ans1[i]][ans1[i+1]];
        }
    }
    cout<<"Case "<<test<<": ";
    cout<<min({costt,costt1})<<endl;
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

