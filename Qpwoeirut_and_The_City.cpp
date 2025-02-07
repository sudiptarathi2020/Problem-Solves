#include<bits/stdc++.h>
#define ll long long 
using namespace std;
void sol(){
    ll n;cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    if(n&1){
        ll ans=0;
        for(ll i=1;i<n;i+=2){
            ans+=max(0LL,max(v[i-1],v[i+1])-v[i]+1);
        }
        cout<<ans<<endl;return;
    }
    vector<ll>pref(n);
    pref[0]=0,pref[n-1]=0;
    for(ll i=1;i<n-1;i++){
        pref[i]=max(0LL,max(v[i-1],v[i+1])-v[i]+1);
    }
    for(ll i=2;i<n;i+=1){
        pref[i]+=pref[i-2];
    }
    ll ans=LLONG_MAX;
    for(ll i=0;i<n;i+=2){
        if(i==0){
            ans=min(ans,pref[n-2]-pref[0]);
        }else if(i==n-2){
            ans=min(ans,pref[i-1]);
        }else{
            ans=min(ans,pref[i-1]+pref[n-2]-pref[i]);
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;cin>>t;
    while(t--)sol();
    return 0;
}
