#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<ll,ll>;
const ll mod=1e9+7;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n;scanf("%lld",&n);
    ll a[n][n];
    memset(a,0,sizeof(a));
    for(ll i=0;i<n;i++){
        char c[n];
        scanf("%s",c);
        for(ll j=0;j<n;j++){
            if(c[j]=='*'){
                a[i][j]=-1;
            }
        }
    }
    for(ll i=0;i<n;i++){
        if(a[0][i]==-1)break;
        a[0][i]=1;
    }
    for(ll i=0;i<n;i++){
        if(a[i][0]==-1)break;
        a[i][0]=1;
    }
    for(ll i=1;i<n;i++){
        for(ll j=1;j<n;j++){
            if(a[i][j]==-1)continue;
            if(a[i][j-1]!=-1){
                a[i][j]+=a[i][j-1];
                a[i][j]%=mod;
            }
            if(a[i-1][j]!=-1){
                a[i][j]+=a[i-1][j];
                a[i][j]%=mod;
            }
        }
    }
    if(a[n-1][n-1]==-1)printf("0\n");
    else printf("%lld\n",a[n-1][n-1]);
    return 0;
}
