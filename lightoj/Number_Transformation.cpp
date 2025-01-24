
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
const ll N=2010;
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
vector<ll>v(N+1);
vector<ll>vv[2*N+1];
vector<ll> divisors(ll n){
    vector<ll>ans;  
    if(v[n]==n){
        return ans;
    }
    while(n!=1){
        if(v[n]!=1){
			ans.pb(v[n]);
		}
        ll k=v[n];
        while(n%k==0){
            n/=k;
        }
    }
    sort(all(ans));
    return ans;
}
void sol(ll test){
    ll source,target;cin>>source>>target;
    vl level(N+1,-1);
    level[source]=0;;
    vl vis(N+1);
    vl path(N+1);
    ql q;q.push(source);
    cout<<"Case "<<test<<": ";
    while(q.size()){
        ll x=q.front();
        q.pop();
        if(vis[x])continue;
        vis[x]=true;
        for(ll u:vv[x]){
            if(!vis[u] and level[u]==-1){
                q.push(u);
                level[u]=level[x]+1;
            }
        }
    }
    cout<<level[target]<<endl;
}
int main(){
    for(ll i=0;i<N;i++){
        v[i]=i;
    }
    for(ll i=2;i*i<=N;i++){
        if(v[i]==i){
            for(ll j=i*i;j<N;j+=i){
                v[j]=min(v[j],i);
            }
        }
    }
    for(ll i=2;i<N;i++){
       if(v[i]==i)continue; 
       vl t=divisors(i);
       for(ll x:t){
           if(x+i<1010){
                vv[i].pb(x+i);
           }
       }
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}

