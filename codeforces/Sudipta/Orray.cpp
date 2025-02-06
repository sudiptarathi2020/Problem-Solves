#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
void sol(){
    ll n;cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    map<ll,bool>ind;
    vector<ll>ans;
    ll check=0;
   
    vector<bool>used(32,false);;
    for(ll i=31;i>=0;i--){
        ll mx=check;
        ll cur=-1;
        for(ll j=0;j<n and used[i]==false;j++){
            if((1<<i)&v[j]){
               ll kt=check|v[j];
                if(kt>mx){
                    mx=kt;
                    cur=j;
                }
            }
        }
        if(cur!=-1){
            ans.push_back(v[cur]);
            check|=v[cur];
            ind[cur]=true;
            for(ll i=0;i<31;i++){
                if(check&(1<<i)){
                    used[i]=true;
                }
            }
        }
    }
    for(ll i=0;i<n;i++){
        if(ind[i])continue;
        ans.push_back(v[i]);
    }
    for(ll i=0;i<n;i++){
        cout<<ans[i]<<" ";
       // if(i){
          //  ans[i]|=ans[i-1];
        //}
      //  cout<<" changed "<<ans[i]<<" "; 
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
