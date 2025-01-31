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
    ll n;cin>>n;
    vector<long double>v(n); 
    F0R(i,n){
        cin>>v[i];
    }
    ll mx=n-2;
    if(n<=2){
        cout<<0<<endl;
        return ;
    }
    F0R(i,n-1){
        FOR(j,i+1,n){
            long double t=(long double)(v[j]-v[i])/((long double)j-(long double)i);
            ll ans=0;
            F0R(k,n){
                if(k==i or k==j)continue;
                long double kk=(long double)v[j]+(long double)(k-j)*(long double)t; 
                if(kk==v[k]){

                    continue;
                }else{
                    ans++;
                }
            }
            mx=min(mx,ans);
        }
    }
    cout<<mx<<endl;
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
