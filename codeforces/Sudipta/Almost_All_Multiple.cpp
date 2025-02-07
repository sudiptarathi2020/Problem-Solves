#include<bits/stdc++.h>
#define ll long long 
using namespace std;
void sol(){
    ll n;cin>>n; 
    ll k;cin>>k;
    vector<ll>v(n+1);
    iota(v.begin(),v.end(),0);
    v[1]=k;v[n]=1;
    if(v[k]==k){
        v[k]=n;
    }
    if(n%k){
        cout<<"-1\n";return;
    }else{
        ll prev=k;
        for(ll i=k+1;i<n;i++){
            if(n%i==0 and i%prev==0){
                swap(v[i],v[prev]);
                prev=i;
            }
        }
        for(ll i=1;i<=n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }





    return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;cin>>t;
    while(t--)sol();
    return 0;
}
