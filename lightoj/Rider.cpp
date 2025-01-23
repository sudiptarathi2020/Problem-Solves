
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define IN cin
#define out cout
#define mkp make_pair
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
#define rev reverse
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
const ll mod=1e9+7;
void sol(ll test);
int main(){
//	freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}
void sol(ll test){
    ll n,m;cin>>n>>m;
    vector<vl>v(n,vl(m));
    //vector<vector<vl>>check(n,vector<vl>(m));
    vector<vl>check(n,vl(m));
    vector<vl>dist(n,vl(m));
    ll dx[]={1,1,-1,-1,2,2,-2,-2};
    ll dy[]={2,-2,2,-2,1,-1,1,-1};
    int cnt=0;
    F0R(i,n){
        F0R(j,m){
            vector<vl>temp(n,vl(m));
            vector<vl>vis(n,vl(m));
            char c;cin>>c;
            if(c=='.'){
                continue;
            }
            cnt++;
            v[i][j]=c-'0';
            //cout<<v[i][j]<<" ";
            qpl q;
            q.push({i,j});
            temp[i][j]=0;
            
            while(q.size()){
                auto it=q.front();
                q.pop();
                if(vis[it.first][it.second])continue;
                vis[it.first][it.second]=1;
                check[it.first][it.second]++;
                F0R(k,8){
                    ll x=it.first+dx[k];
                    ll y=it.second+dy[k];
                    if(x>=0 and y>=0 and x<n and y<m and !vis[x][y]){
                        temp[x][y]=temp[it.first][it.second]+1;
                        
                        q.push(mkp(x,y));
                    }
                }
            }
            //cout<<"i,j: "<<i<<" "<<j<<endl;
            //~ F0R(k,n){
                //~ F0R(p,m){
                    //~ cout<<k<<" : "<<p<<" : "<<temp[k][p]<<endl;
                //~ }
            //~ }
            F0R(k,n){
                F0R(p,m){
                    if(temp[k][p]%v[i][j]!=0){
                        dist[k][p]+=(temp[k][p]/v[i][j]);
                        dist[k][p]++;
                    }else{
                        dist[k][p]+=(temp[k][p]/v[i][j]);
                    }
                }
            }
            
        }
    }
    ll ans=inf;
    F0R(i,n){
        F0R(j,m){
            if(check[i][j]==cnt){
				ans=min(ans,dist[i][j]);
			}
        }
    }
    if(ans==inf){
		out<<"Case "<<test<<": "<<"-1"<<endl;
	}else{
		out<<"Case "<<test<<": "<<ans<<endl;
	}
}
