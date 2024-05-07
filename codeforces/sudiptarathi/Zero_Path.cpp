//https://codeforces.com/problemset/problem/1695/C
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void sol(){
    ll n,m;cin>>n>>m;
    ll Min[n][m],Max[n][m],arr[n][m];
    for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)cin>>arr[i][j];
    Min[0][0]=Max[0][0]=arr[0][0];
    if((n+m)%2==0){
        cout<<"NO\n";
        return;
    }
    for(ll i=1;i<n;i++){
        Min[i][0]=Max[i][0]=Min[i-1][0]+arr[i][0];
    }
    for(ll i=1;i<m;i++){
        Min[0][i]=Max[0][i]=Min[0][i-1]+arr[0][i];
    }
    for(ll i=1;i<n;i++){
        for(ll j=1;j<m;j++){
            Min[i][j]=min(Min[i-1][j],Min[i][j-1])+arr[i][j];
            Max[i][j]=max(Max[i-1][j],Max[i][j-1])+arr[i][j];
        }
    }
    if(Min[n-1][m-1]>0 or Max[n-1][m-1]<0){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
    }
}
int main(){
    int t;cin>>t;while(t--)sol();
}
