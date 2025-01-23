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
void sol(ll test){
    ll n,x;cin>>n>>x;
    vector<ll>a,b;
    for(ll i=0;i<n;i++){
        ll c;cin>>c;
        if(i&1){
            a.pb(c);
        }else{
            b.pb(c);
        }
    }
    vector<ll>c,d;
    unordered_map<ll,ll>mp;
    for(ll i=0;i<=(1<<(ll)a.size())-1;i++){
        ll x=0;
        for(ll j=0;j<(ll)a.size();j++){
            if(i&(1<<j)){
                x+=a[j];
            }
        }
        c.pb(x);
    }
    sort(all(c));
    for(ll i=0;i<=(1<<(ll)b.size())-1;i++){
        ll x=0;
        for(ll j=0;j<(ll)b.size();j++){
            if(i&(1<<j)){
                x+=b[j];
            }
        }
        mp[x]++;
        d.pb(x);
    }
    ll cnt=0;
    sort(all(d));
    for(ll U:c){
        if(U==x){
            cnt++;
            continue;
        }
        auto y=lower_bound(all(d),x-U);
        if(y==d.end()){
            continue;
        }
        if(*y==x-U){
            cnt+=mp[*y];
        }
    }
 
    cout<<cnt<<endl;
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;//cin>>t;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}
