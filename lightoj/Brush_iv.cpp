
#include<bits/stdc++.h>
#include <utility>
#define ll long long
#define F first
#define S second
using pii=std::pair<int,int>;
using namespace std;
const int mod=1e9+7;
const int N=16;
pii a[N];
int Msk[N][N];
int dp[1<<N];
bool same_line(pii a,pii b,pii c){
    return a.F*b.S+b.F*c.S+c.F*a.S-a.S*b.F-b.S*c.F-c.S*a.F==0;
}
int ok(int mask,int n){
    if(dp[mask]!=-1)return dp[mask];
    if(mask==(1<<n)-1)return dp[mask]=0;
    int cnt=__builtin_popcount(mask);
    if(cnt==n-1 or cnt==n-2)return dp[mask]=1;
    int ans=8;//max answer possible
    for(int i=0;i<n;i++){
        if(mask&(1<<i))continue;
        for(int j=i+1;j<n;j++){
            if(mask&(1<<j))continue;
            ans=min(ans,1+ok(mask|Msk[i][j],n));
        }
        break;
    }
    return dp[mask]=ans;
}
void sol(int test){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    for(int i=0;i<(1<<n);i++){
        dp[i]=-1;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int X=0;
            X|=(1<<i);
            X|=(1<<j);
            for(int k=0;k<n;k++){
                if(same_line(a[i],a[j],a[k])){
                    X|=(1<<k);
                }
            }
            Msk[i][j]=X;
        }
    }
    cout<<"Case "<<test<<": "<<ok(0,n)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
}

