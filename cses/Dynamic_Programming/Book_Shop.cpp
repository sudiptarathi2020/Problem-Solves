#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
vector<int>price,pages;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,x;cin>>n>>x;
    price.resize(n),pages.resize(n);
    for(int &_:price)cin>>_;
    for(int &_:pages)cin>>_;
    dp.resize(n+1,vector<int>(x+1,0));
    for(int i=0;i<=n;i++){
        for(int W=0;W<=x;W++){
            if(i==0 or W==0){
                dp[i][W]=0;
            }else if(price[i-1]<=W){
                dp[i][W]=max(pages[i-1]+dp[i-1][W-price[i-1]],dp[i-1][W]);
            }else{
                dp[i][W]=dp[i-1][W];
            }
        }
    }
    cout<<dp[n][x]<<endl;
}
