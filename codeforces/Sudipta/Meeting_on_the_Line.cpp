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
const ll N=2e5;
const ll mod=1e9+7;
typedef pair<ll,ll> pl;
typedef pair<ld,ld>pld;
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
pld intersect(pld a,pld b){
    if(a.fst>b.scnd||b.fst>a.scnd){
        return make_pair((ld)-1,(ld)-1);
    }
    return mkp(max(a.fst,b.fst),min(a.scnd,b.scnd));
}
void sol(ll test){
    ll n;cin>>n;
    ld a[n],b[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    ld low=(ld)0,high=(ld)2e8+5;
    ld ans=(ld)0;
    ll iter=60;
    while(iter--){
        ld mid=(low+high)/2.0;
        ll ok=1;
        pld aa=mkp((ld)0,(ld)1e8+1);
        for(ll i=0;i<n;i++){
            if(mid<b[i]){
                ok=0;
                break;
            }
            ld dif=mid-b[i];
            pair<ld,ld> b=make_pair((ld)a[i]-dif,(ld)a[i]+dif);
            aa=intersect(b,aa);
            if(aa.fst==(ld)-1){
                ok=0;
                break;
            }
        }
        if(ok){
            ans=(ld)(aa.fst+aa.scnd)/2.0;
            high=mid;
        }else{
            low=mid;
        }
    }
    cout<<setprecision(12)<<ans<<endl;
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}
 
