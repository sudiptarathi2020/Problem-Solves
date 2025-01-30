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
const ll NN=2e3+1;
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
vector<vector<int>>v(NN,vector<int>(NN));
vector<vector<bool>>vis(NN,vector<bool>(NN));
int cnt=0;
void dfs(int x,int y,int n){
    vis[x][y]=true;
    if(v[x][y]==1){
		cnt++;
	}
	int dx=(x+1)%n;
	int dy=(y+1)%n;
	if(!vis[dx][dy]){
		dfs(dx,dy,n);
	}
}
void sol(ll test){
    int n;cin>>n;
    string s;
    for(int i=0;i<n;i++){
		string ss;cin>>ss;
        for(int j=0;j<n;j++){
            v[i][j]=(ss[j]=='0')?0:1;
            vis[i][j]=0;
        }
    }
    vector<vector<int>>arr(n,vector<int>(n));
    int mx=0;
    int x=0,y=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==1 and !vis[i][j]){
                cnt=0;
                dfs(i,j,n);
                if(cnt>mx){
                    mx=cnt;
                    x=i,y=j;
                }
            }
        }
    }
    x=n-x,y=n-y; 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[(i+x)%n][(j+y)%n]=v[i][j];
        }
    }
    cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j and arr[i][j]==1){
                cnt++;
            }
            if(i==j and arr[i][j]==0){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;cin>>t;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}
 
