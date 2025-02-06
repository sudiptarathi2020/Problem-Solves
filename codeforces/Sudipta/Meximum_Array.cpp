#include<bits/stdc++.h>
#define ll long long 
using namespace std;
void sol(){
    ll n;cin>>n;
    vector<ll>v(n);
    ll mx=LLONG_MIN;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        mx=max(mx,v[i]);
    }
    vector<bool>vis(n+1);
    vector<ll>suf(n);
    ll init=0;
    for(ll i=n-1;i>=0;i--){
        if(v[i]==init){
            vis[v[i]]=true;
            while(vis[init]){
                init++;
            }
        }else{
            vis[v[i]]=true;
        }
        suf[i]=init;
    }
    
    vector<ll>ans;
    for(ll i=0;i<n;i++){
        ll k=suf[i];
        map<ll,bool>mp;
        ll ini=0;
        for(ll j=i;j<n;j++){
            if(v[j]==ini){
                mp[v[j]]=true;
                while(mp[ini]){
                    ini++;
                }
            }else{
                mp[v[j]]=true;
            }
            if(ini==k){
                i=j;
                ans.push_back(ini);
                break;
            }
        }
    }
    cout<<(ll)ans.size()<<endl;
    for(ll I:ans){
        cout<<I<<" ";
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;cin>>t;
    while(t--)sol();
    return 0;
}
