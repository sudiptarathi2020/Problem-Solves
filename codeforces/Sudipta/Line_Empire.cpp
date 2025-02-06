#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
#define all(s) (s).begin(),(s.end())
#define sz(x) (ll)(x).size();
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
using namespace std;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vpl;
void sol(){
    ll n;cin>>n;
    ll a,b;cin>>a>>b;
    vl v(n+1);
    v[0]=0;
    vl pref(n+1);
    FOR(i,1,n+1){
        cin>>v[i];
        pref[i]=v[i]+pref[i-1];

    }
    ll mx=LLONG_MAX;
    F0R(i,n+1){
        ll ans=v[i]*a+v[i]*b;
        ans+=b*(pref.back()-pref[i]-(n-i)*v[i]);;
        mx=min(mx,ans);

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
