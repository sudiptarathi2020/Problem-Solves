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
void sol(){
    ll n,m;cin>>n>>m;
    vector<vl>v(n,vl(m));
    ll cnt=0;
    vl sum(n);
    F0R(i,n){
        F0R(j,m){
            cin>>v[i][j];
            cnt+=v[i][j];
            sum[i]+=v[i][j]; 
        }
    }
    if(cnt%n){
        cout<<"-1\n";return;
    }
    ll num=cnt/n;
    vector<array<ll,3>>ans;
    F0R(i,m){
        vl a,b;
        F0R(j,n){
            if(sum[j]>num and v[j][i]==1)a.pb(j);
            if(sum[j]<num and v[j][i]==0)b.pb(j);
        }
        F0R(k,(ll)min(a.size(),b.size())){
            sum[a[k]]--,sum[b[k]]++;
            ans.pb({a[k],b[k],i});
        }
    }
    cout<<ans.size()<<endl;
    for(array<ll,3>x:ans){
        cout<<x[0]+1<<" "<<x[1]+1<<" "<<x[2]+1<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
