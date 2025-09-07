#include<string.h>
#define N 46
static int dp[N];
int climbstairs(int n) {
    if(dp[n]!=-1){
        return dp[n];
    }
    if(n==2){
        return 2;
    }else if(n==1){
        return 1;
    }
    return dp[n]=climbstairs(n-2)+climbstairs(n-1);
}
int climbStairs(int n){
    memset(dp,-1,sizeof(dp));
    int ans = climbstairs(n);
    return ans;
}
