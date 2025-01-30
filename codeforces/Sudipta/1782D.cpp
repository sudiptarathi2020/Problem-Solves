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
    ll n;cin>>n;
    vl arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    map<ll,set<ll>>mp;
    for(int ii=0;ii<n-1;ii++){
        for(int j=ii+1;j<n;j++){
            int k=arr[j]-arr[ii];
            for(int i=1;i*i<=k;i++){
                if(k%i==0){
                    ll d=i;         
                    if(((k/d)+d)%2==0 and ((k/d)-d)%2==0 and (k/d)>d){
                        ll y=((k/d)+d)/2;                        
                        ll x=y*y-arr[j];
                        if(x<0)continue;
                        mp[x].insert(arr[j]);
                        mp[x].insert(arr[ii]);
                    }
                    d=k/i;
                    if(((k/d)+d)%2==0 and ((k/d)-d)%2==0 and (k/d)>d){
                        ll y=((k/d)+d)/2;
                        ll x=y*y-arr[j];
                        if(x<0)continue;
                        mp[x].insert(arr[j]);
                        mp[x].insert(arr[ii]);
                    }
                }
            }
        }
    }
    ll ans=0;
    if(mp.size()==0){
        cout<<1<<endl;
        return;
    }
    for(auto it:mp){
        ans=max(ans,(ll)it.second.size());
    }
    cout<<ans<<endl;
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
 