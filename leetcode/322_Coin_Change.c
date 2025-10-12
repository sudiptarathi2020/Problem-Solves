int coinChange(int* coins, int coinsSize, int amount) {
    int np = 99999999;
    int dp[amount+1];dp[0]=0;
    for(int i=1;i<=amount;i++)dp[i]=np;
    for(int i=0;i<coinsSize;i++){
        for(int j=0;j<=amount;j++){
            if(j-coins[i]>=0 && dp[j]>dp[j-coins[i]]+1){
                dp[j]=dp[j-coins[i]]+1;
            }
        }
    }
    return dp[amount]==np?-1:dp[amount];
}
