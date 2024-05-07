//https://codeforces.com/problemset/problem/1462/E2
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
const ll N=3e5+1;
const ll mod=1000000007;
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
vl fact(N);
vl inv(N);
ll binpow(ll a,ll k){
    ll ans=1;
    F0R(i,32){
        if(k<(1<<i)){
            break;
        }
        if(k&(1<<i)){
            ans*=a;
            ans%=mod;
        }
        a*=a;
        a%=mod;
    }
    return ans;
}
ll NCR(ll n,ll r){
    if(r>n){
        return 0;
    }
    return (fact[n]*inv[r]%mod*inv[n-r]%mod)%mod;
}
void sol(ll test){
    ll n,m,k;IN>>n>>m>>k;    
    vl arr(n);
    F0R(i,n)IN>>arr[i];
    sort(all(arr));
    ll ans=0;
    F0R(i,n){
        ll it=ub(all(arr),arr[i]+k)-arr.begin();;
        ll num=it-i-1;
        if(num>=m-1){
            ll kt=NCR(num,m-1)%mod;
            ans=ans+kt;
            ans%=mod;
        }else{
            continue;
        }
    }
    out<<ans<<endl;
    return;
}
int main(){
    fact[0]=inv[0]=1;
    F0R(i,N){
        if(!i)continue;
        fact[i]=i;
        fact[i]*=fact[i-1];
        fact[i]%=mod;
    }
    F0R(i,N){
        if(!i)continue;
        inv[i]=binpow(fact[i],mod-2);
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
}


