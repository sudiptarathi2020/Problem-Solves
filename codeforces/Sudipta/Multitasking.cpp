#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mkp make_pair
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
    ll n,m,k;cin>>n>>m>>k;
    vector<vl>v(n,vl(m));
    F0R(i,n){
        F0R(j,m){
            cin>>v[i][j];
        }
    }
    cout<<(m-1)*(m)/2<<endl;
    if(k==0){
        F0R(i,m-1){
            FOR(j,i+1,m){
                cout<<i+1<<" "<<j+1<<endl;
            }
        }
    }
    else{
        for(int i=m-1;i>0;i--){
            for(int j=i-1;j>=0;j--){
                cout<<i+1<<" "<<j+1<<endl;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;//cin>>t;
    while(t--)sol();
    return 0;
}
