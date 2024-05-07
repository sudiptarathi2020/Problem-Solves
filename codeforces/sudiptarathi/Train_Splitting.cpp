//https://codeforces.com/problemset/problem/1776/F
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
    ll a,b,n,m;cin>>n>>m;
    vector<vector<ll>>edges(n+1);
    vector<pair<ll,ll>>A;
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        A.push_back({a,b});
    }
    for(ll i=1;i<=n;i++){
        if((ll)edges[i].size()<n-1){
            cout<<2<<endl;
            for(ll j=0;j<m;j++){
                if(A[j].first!=i and A[j].second!=i){
                    cout<<2<<" ";
                }else{
                    cout<<1<<" ";
                }
            }
            cout<<endl;
            return;
        }
    }
    bool banaisi=false;
    cout<<3<<endl;
    for(ll j=0;j<m;j++){
        if(A[j].first==1 or A[j].second==1){
            if(!banaisi){
                cout<<1<<" ";
                banaisi=true;
            }else{
                cout<<2<<" ";
            }
        }else{
            cout<<3<<" ";
        }
    }
    cout<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
}


