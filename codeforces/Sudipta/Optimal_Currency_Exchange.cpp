#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
void sol(){
    ll w,d,e;cin>>w>>d>>e;
    e*=5;
    ll ans=LLONG_MAX;
    for(ll i=0;i*e<=w;i++){
        ll k=w-i*e;
        ans=min(ans,k%d);
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
