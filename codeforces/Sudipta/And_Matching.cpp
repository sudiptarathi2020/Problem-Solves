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
#define FOR(i,a,b) for(ll i=a;i<(b);i++)
#define F0R(i,a) for(ll i=0;i<(a);i++)
#define ford(i,a,b) for(ll i=a;i>=b;i--)
#define f0rd(i,a) for(ll i=a;i>=0;i--)
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
    ll n;cin>>n;
    ll k;cin>>k;
    if(k==0){
        F0R(i,n/2){
            cout<<i<<" "<<((n-1)^i)<<endl;
        }
        return ;
    }else if(k==n-1){
        if(n==4){
            cout<<"-1"<<endl;
            return;
        }
        cout<<n-1<<" "<<n-2<<endl;
        cout<<n-3<<" "<<1<<endl;
        cout<<((n-1)^(n-3))<<" "<<0<<endl;
        F0R(i,n/2){
            if(i==0 or i==n-1 or i==n-2 or i==n-3 or i==1 or i==((n-1)^(n-3))){
                continue;
            }
            cout<<i<<" "<<((n-1)^i)<<endl;
        }
    }else{
        cout<<n-1<<" "<<k<<endl;
        cout<<((n-1)^(k))<<" "<<0<<endl;
        F0R(i,n/2){
            if(i==0 or i==k or i==n-1 or i==((n-1)^k))continue;
            cout<<i<<" "<<((n-1)^i)<<endl;
        }
    }
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
