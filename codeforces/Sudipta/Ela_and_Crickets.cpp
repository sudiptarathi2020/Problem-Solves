#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
using namespace std;
void sol(){
    ll n;cin>>n;
    vector<pair<ll,ll>>v(3);
    for(ll i=0;i<3;i++){
        cin>>v[i].first>>v[i].second;
        v[i].first=n+1-v[i].first;
        v[i].second=n+1-v[i].second;
    }
    ll x,y;cin>>x>>y;
    x=n+1-x,y=n+1-y;
    ll a=(v[0].first==v[1].first)?v[0].first:v[2].first;
    ll b=(v[0].second==v[1].second)?v[0].second:v[2].second;
    ll aa=a+1;
    ll bb=b+1;
    if(x==a ||b==y){
        cout<<"YES ";
        return ;
    }
    if(a==1 and b==1){
        cout<<"NO ";
        return;
    }
    if(a==1 and b==n){
        cout<<"NO ";
        return;
    }
    if(a==n and b==n){
		
        cout<<"NO ";
   
       return;
    }
    if(a==n and b==1){
		
        cout<<"NO ";
     
       return;
    }
    if(abs(aa-x)%2==0 and abs(bb-y)%2==0){
        cout<<"NO ";
     
    }else{
        cout<<"YES ";
      
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
