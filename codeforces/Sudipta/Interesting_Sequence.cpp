#include<bits/stdc++.h>
#define ll unsigned long long
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
const ll mod=(ll)1e9+7;
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
void sol(){
    ll a,b;cin>>a>>b;
    swap(a,b);
    if(a==b){
        cout<<a<<endl;
        return;
    }
    ll c=a&(-a); 
    ll j=0;
    if(a==0){
        for(ll i=0;i<=63;i++){
            if(b&((ll)1<<i)){
                j=i;
            }
        }
    }
    if(a==0){
        cout<<((ll)1<<(j+(ll)1))<<endl;
        return;
    }
    for(ll i=0;i<=63;i++){
        if((a&((ll)1<<i))==c){
            j=i;
        }
        if((a&((ll)1<<i)) and (b&((ll)1<<i))==0){
            cout<<"-1\n";
            return;
        }
        if((a&((ll)1<<i))==0 and (b&((ll)1<<i)) and ((ll)1<<i)>=c){
            cout<<"-1\n";
            return;
        }
    }
    int p=(int)j;
    for(ll i=j;i>=0;i--){
        if(!p){
            break;
        }
        if((b&((ll)1<<i))){
            if(i==j-(ll)1){
                cout<<"-1\n";
                return;
            }
            if(i==j)continue;
            b|=((ll)((ll)1<<(i+(ll)1))); 
            for(int k=(int)i;k>=0;k--){
                b=b & ~((ll)1<<k);
            }
            cout<<b<<endl;
            return;
        }
        p--;
    }
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        sol();
    }
    return 0;
}
 
