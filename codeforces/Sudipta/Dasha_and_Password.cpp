#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
#define mkp make_pair
#define fst first
#define scnd second
#define all(s) (s).begin(),(s.end())
#define sz(x) (ll)(x).size();
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define f0rd(i,a) for(int i=a;i>=0;i--)
using namespace std;
const ll inf=1000000;
const ll ninf=LLONG_MIN;
const ll mod=1e9+7;
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
    vs s(n);
    vector<array<ll,3>>arr(n);
    F0R(i,n){
        cin>>s[i];
        vl a,b,c;
        F0R(j,m){
            if(s[i][j]<='z' and s[i][j]>='a'){
                a.pb(j);
            }else if(s[i][j]=='#' or s[i][j]=='*' or s[i][j]=='&'){
                b.pb(j);
            }else{
                c.pb(j);
            } 
        }
        if(a.size())
            arr[i][0]=min(a.front(),m-a.back());
        else
            arr[i][0]=inf;
        if(b.size())
            arr[i][1]=min(b.front(),m-b.back());
        else
            arr[i][1]=inf;
        if(c.size())
            arr[i][2]=min(c.front(),m-c.back());
        else
            arr[i][2]=inf;
    }
    ll ans=inf;
    F0R(i,n){
        F0R(j,n){
            if(i==j)continue;
            F0R(k,n){
                if(k==i or k==j){
                    continue;
                }
                F0R(ii,3){
                    F0R(jj,3){
                        if(ii==jj)continue;
                        F0R(kk,3){
                            if(kk==ii or kk==jj)continue;
                            ans=min(ans,arr[i][ii]+arr[j][jj]+arr[k][kk]);
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;//cin>>t;
    while(t--)sol();
    return 0;
}
