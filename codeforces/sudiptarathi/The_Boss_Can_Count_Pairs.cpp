//https://codeforces.com/problemset/problem/1830/B
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void sol(){
    ll n;cin>>n;
    pair<ll,ll> A[n];
    for(ll i=0;i<n;i++){
        cin>>A[i].first;
    }
    for(ll i=0;i<n;i++){
        cin>>A[i].second;
    }
    ll AA[2*n];
    ll ans=0;
    sort(A,A+n);
    for(ll i=1;i*i<=2*n;i++){
        memset(AA,0,sizeof(AA));
        for(auto X:A){
            ll P=X.first*i-X.second;
            if(P>=1 and P<=n){
                ans+=AA[P];
            }
            if(i==X.first){
                AA[X.second]++;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;while(t--)sol();
}
