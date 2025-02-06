#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
void sol(){
    ll n;cin>>n;
    ll k;cin>>k;
    vector<ll>v(n);
    map<ll,vector<ll>>mp;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        if(mp[v[i]].size()<k){
            mp[v[i]].pb(i);
        }
        
    }
    ll ocur=0;
    for(auto I:mp){
        ocur+=I.second.size();
    }
    ll cnt=0;
    vector<ll>ans(n);
    ocur-=ocur%k;
    for(auto I:mp){
        for(auto L:I.second){
            ans[L]=++cnt;
            cnt%=k;
            ocur--;
            if(ocur==0){
                for(auto P:ans){
                    cout<<P<<" ";
                }
                cout<<endl;
                return ;
            }
        }
    }




}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
