#include<bits/stdc++.h>
#define ll long long
const ll inf = LLONG_MAX;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,m,q;cin>>n>>m>>q;
    ll dist[n+1][n+1];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            dist[i][j]=inf;
        }
        dist[i][i]=0;
    }
    while(m--){
        ll a,b,c;cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c);
        dist[b][a]=min(dist[b][a],c);
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                if(dist[j][k]>dist[j][i]+dist[i][k] and dist[j][i]!=inf and dist[i][k]!=inf){
                    dist[j][k]=dist[j][i]+dist[i][k];
                }
            }
        }
    }
    while(q--){
        ll a,b;cin>>a>>b;
        cout<<(dist[a][b]==inf?-1:dist[a][b])<<endl;
    }
}
