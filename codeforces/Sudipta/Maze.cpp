#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
#define fst first
#define scnd second
#define all(s) (s).begin(),(s.end())
#define sz(x) (ll)(x).size();
#define mkp make_pair
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
ll dx[]={1,0,-1,0};
ll dy[]={0,1,0,-1};
void sol(){
    ll n,m;cin>>n>>m;
    ll k;cin>>k;
    ll px=-1,py=-1;
    char s[n][m];
    F0R(i,n){
        F0R(j,m){
            cin>>s[i][j];
            if(s[i][j]=='.' and px==-1 and py==-1){
                px=i;
                py=j;
            }
        }
    }
    vpl v;
    queue<pl>q;
    map<pl,ll>vis;
    q.push({px,py});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        if(vis[it])continue;
        vis[it]=true;
        v.push_back(it);
        F0R(i,4){
            ll x=it.fst+dx[i];
            ll y=it.scnd+dy[i];
            if(x>=0 and x<n and y>=0 and y<m ){
                if(!vis[mkp(x,y)] and s[x][y]=='.'){
                    q.push(mkp(x,y)); 
                }
            }
        }
    }
    reverse(all(v));
    F0R(i,k){
        s[v[i].fst][v[i].scnd]='X';
    }
    F0R(i,n){
        F0R(j,m){
            cout<<s[i][j];
        }
        cout<<endl;
    }

    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;//cin>>t;
    while(t--)sol();
    return 0;
}
