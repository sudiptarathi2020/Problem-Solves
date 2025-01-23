
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
const ll N=17600;
vector<ll>v[N];
vector<vector<vector<ll>>>arr(26,vector<vector<ll>>(26,vector<ll>(26)));
void sol(ll test){
    string s;cin>>s;
    ll source=arr[s[0]-'a'][s[1]-'a'][s[2]-'a'];
    string s1;cin>>s1;
    ll dest=arr[s1[0]-'a'][s1[1]-'a'][s1[2]-'a'];
    ll n;cin>>n;
    vector<bool>forbidden(N),vis(N);;
    vector<ll>dist(N);
    F0R(i,n){
        string a,b,c;cin>>a>>b>>c;
        for(char x:a){
            for(char y:b){
                for(char z:c){
                    forbidden[arr[x-'a'][y-'a'][z-'a']]=true;
                }
            }
        }
    }
    cout<<"Case "<<test<<": ";
    if(forbidden[source] or forbidden[dest]){
        cout<<"-1\n";return;
    }
    if(s==s1){
        cout<<"0\n";return;
    }
    queue<ll>q;
    q.push(source);
    dist[source]=0;
    while(q.size()){
        ll x=q.front();
        q.pop();
        if(vis[x])continue;
        vis[x]=true;
        for(ll u:v[x]){
            if(not vis[u] and not forbidden[u]){
                q.push(u);
                dist[u]=dist[x]+1;
            }
        }
    }
    if(not vis[dest]){
        cout<<"-1\n";return;
    }
    cout<<dist[dest]<<endl;
    return; 
}
int main(){
    ll cnt=0;
    F0R(i,26){
        F0R(j,26){
            F0R(k,26){
                arr[i][j][k]=cnt;
                cnt++;
            }
        }
    }
    F0R(i,26){
        F0R(j,26){
            F0R(k,26){
                ll x=(k+1)%26;
                v[arr[i][j][k]].pb(arr[i][j][x]);
                v[arr[i][j][x]].pb(arr[i][j][k]);
            }
        }
    }
    F0R(i,26){
        F0R(j,26){
            F0R(k,26){
                ll x=(k+1)%26;
                v[arr[i][k][j]].pb(arr[i][x][j]);
                v[arr[i][x][j]].pb(arr[i][k][j]);
            }
        }
    }
    F0R(i,26){
        F0R(j,26){
            F0R(k,26){
                ll x=(k+1)%26;
                v[arr[k][i][j]].pb(arr[x][i][j]);
                v[arr[x][i][j]].pb(arr[k][i][j]);
            }
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}

