#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
int n,maxn;
vector<int>arr;
vector<int>dp;
void sol(int test){
    cin>>n>>maxn;
    dp.resize(maxn+1,1e7);
    arr.resize(n);
    for(int &x:arr)cin>>x;
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=maxn;j++){
            if(j>=arr[i]){
                dp[j]=min(dp[j],dp[j-arr[i]]+1);
            }
        }
    }
    cout<<(dp[maxn]>maxn?-1:dp[maxn])<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
//    cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}
