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
const int N=1e7;
vl v(N+1);
vector<ll> prms(ll a){
    vector<ll>ans;
    while(a>1){
        if(ans.empty() or ans.back()!=v[a]){
            ans.pb(v[a]);
        }
        a/=v[a];
    }
    return ans;
}
void sol(){
    ll a,b;cin>>a>>b;
    if(a<b)swap(a,b);
    a-=b;
    if(a==1){
        cout<<"-1\n";return;
    }
    ll mn=inf;
    for(auto I:prms(a)){
        ll x=b/I;
        if(b%I==0){
           mn=min(mn,b-x*I); 
        }else{
            mn=min(mn,(x+1)*I-b);
        }
    }
    cout<<mn<<endl;
}
int main(){
    F0R(i,N){
        v[i]=i;
    }
    for(ll i=2;i*i<=N;i++){
        if(v[i]==i){
            for(ll j=2*i;j<=N;j+=i){
                v[j]=min(v[j],v[i]);
            }
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        sol();
    }
    return 0;
}
