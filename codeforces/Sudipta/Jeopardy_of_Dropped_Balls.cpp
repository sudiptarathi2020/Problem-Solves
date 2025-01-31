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
    ll n,m,k;cin>>n>>m>>k; 
    vector<vector<ll>>v(n,vector<ll>(m));
    F0R(i,n){

        F0R(j,m){
            cin>>v[i][j];
        }
    }
    F0R(i,k){
        ll a;cin>>a;
        a--;
        bool stp=false;
        ll t=0;
        while(!stp){
            if(v[t][a]==1){
                if(a<m-1){
                    v[t][a]=2;
                    a++;
                }else{
                    stp=true;
                }
            }else if(v[t][a]==2){
                if(t<n-1){
                    v[t][a]=2;
                    t++;
                }else{
                    stp=true;
                }
            }else if(v[t][a]==3){
                if(a>0){
                    v[t][a]=2;
                    a--;
                }else{
                    stp=true;
                }
            }
        }
        cout<<a+1<<" ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;//cin>>t;
    while(t--)sol();
    return 0;
}
