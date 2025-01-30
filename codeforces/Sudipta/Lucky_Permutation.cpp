#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define mkp make_pair
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
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
struct dsu{
    vector<ll>parent;
    vector<ll>Size;
    dsu(){}
    dsu(ll n){
        parent.assign(1+n,0);
        Size.assign(1+n,0);
        for(ll i=1;i<=n;i++){
            parent[i]=i;
            Size[i]=1;
        }
    }
    ll find(ll a){
        if(parent[a]==a){
            return parent[a];
        }else{
            return parent[a]=find(parent[a]);
        }
    }
    void unify(ll a,ll b){
        a=find(a);
        b=find(b);
        if(a==b){
            return;
        }else{
            if(Size[a]<Size[b]){
                swap(a,b);
            }
            parent[b]=a;
            Size[a]+=Size[b];
        }
    }
};
void sol(){
    ll n;cin>>n;
    dsu d(n);
    FOR(i,1,n+1){
        ll a;cin>>a;
        d.unify(i,a);
    }
    st s;
    FOR(i,1,n+1){
        s.insert(d.find(i));
    }
    ll cycles=(ll)sz(s);
    ll ans=inf;
    FOR(i,1,n){
        if(d.find(i)==d.find(i+1)){
            ans=min(ans,n-(cycles+1));
        }else{
            ans=min(ans,n-(cycles-1));
        }
    }
    cout<<ans<<endl;
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
 
