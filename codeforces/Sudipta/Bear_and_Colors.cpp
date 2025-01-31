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
#define mkp make_pair
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
    vl vt(n);
    F0R(i,n){
        cin>>vt[i];
    }
    ll mp[n+1];
    memset(mp,0,sizeof(mp));
    F0R(i,n){
        ll seg[n+1];
        memset(seg,0,sizeof(seg));
        ll cur=0;
        FOR(j,i,n){
            seg[vt[j]]++;
            if(seg[vt[j]]>seg[cur] or (seg[vt[j]]==seg[cur] && vt[j]<cur)){
                cur=vt[j];
            }
            mp[cur]++;
        }
    }
    FOR(i,1,n+1){
        cout<<mp[i]<<" ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;//cin>>t;
    while(t--)sol();
    return 0;
}
