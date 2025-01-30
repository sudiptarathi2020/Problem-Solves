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
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define FORd(i,a,b) for(int i=a;i>=b;i--)
#define F0Rd(i,a) for(int i=a;i>=0;i--)
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
int knp(int W,int wt[],int val[],int n){
    int dp[W+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<n+1;i++){
        for(int w=W;w>=0;w--){
            if(wt[i-1]<=w){
                dp[w]=max(dp[w],dp[w-wt[i-1]]+val[i-1]);
            }
        }
    }
    return dp[W];
}
int main(){
    vector<vector<int>>v(1e3+1);
    for(int i=1;i<=1e3;i++){
        for(int j=1;j<=i;j++){
            int k=i/j;
            if(k==0){
                break;
            }
            v[i].pb(i+k);
        }
    }
    vector<int>level(1e3+1,-1);
    vector<bool>vis(1e3+1);
    queue<int>que;
    que.push(1);
    level[1]=0;
    while(que.size()){
        int x=que.front();
        que.pop();
        if(vis[x])continue;
        vis[x]=true;
        for(int u:v[x]){
            if(u<=1e3 and !vis[u] and level[u]==-1){
                que.push(u);
                level[u]=level[x]+1;
            }
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    FOR(i,1,t+1){
        int k;
        int n;cin>>n>>k;
        int wt[n];
        for(int ii=0;ii<n;ii++){
            cin>>wt[ii];
            wt[ii]=level[wt[ii]];
        }
        int val[n];
        for(int ii=0;ii<n;ii++){
            cin>>val[ii];
        }
        cout<<knp(k,wt,val,n)<<endl;
    }
    return 0;
}
 
