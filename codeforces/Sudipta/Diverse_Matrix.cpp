#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll lcm(ll a,ll b){
    return (a*b)/__gcd(a,b);
}
void sol(){
    ll a,b;cin>>a>>b;
    if(a==b and a==1){
        cout<<0<<endl;
        return ;
    }
    ll aa=a,bb=b;
    if(a>b)
        swap(a,b);
    vector<vector<ll>>v(a,vector<ll>(b));
    for(ll i=0;i<a;i++){
        ll cnt=2;
        for(ll j=0;j<b;j++){
            v[i][j]=cnt;cnt++;
        }
    }
    ll cnt=b+2;
    for(ll i=1;i<a;i++){
        for(ll j=0;j<b;j++){
            v[i][j]=lcm(cnt,v[0][j]);
        }
        cnt++;
    }
    if(aa>=bb){
        for(ll i=0;i<b;i++){
            for(ll j=0;j<a;j++){
                cout<<v[j][i]<<" ";
            }
            cout<<endl;
        }
    }else{
        for(ll i=0;i<a;i++){
            for(ll j=0;j<b;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    while(t--)sol();
    return 0;
}
