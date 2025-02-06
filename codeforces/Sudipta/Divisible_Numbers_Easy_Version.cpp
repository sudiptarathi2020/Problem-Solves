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
    ll a,b,c,d;cin>>a>>b>>c>>d;
    ll k=a*b;
    FOR(i,a+1,c+1){
        ll kt=__gcd<ll>(k,i);
        ll t=(k)/kt;
        ll ans=(d)/t;
        if(ans*t<=d and ans*t>b){
            cout<<i<<" "<<ans*t<<endl;
            return ;
        }
    }
    cout<<"-1 -1"<<endl;

    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
