#include <algorithm>
#include<bits/stdc++.h>
#include <sys/types.h>
#include <vector>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices,int kinechi,size_t idx,vector<vector<int>>& dp){
            if(idx==prices.size())return 0;
            int ans = 0;
            if(kinechi==-1){
                ans = max(maxProfit(prices,idx,idx+1,dp),maxProfit(prices,kinechi,idx+1,dp));
            }else{
                ans = max(maxProfit(prices,-1,idx+1,dp)+prices[idx]-prices[kinechi],maxProfit(prices,kinechi,idx+1,dp));
            }
            return ans;
        }
        int maxProfit(vector<int>& prices) {
            size_t sz= prices.size();
            vector<vector<int>>dp(sz,vector<int>(sz,-1));
            return maxProfit(prices,-1,0,dp);
        }
};
int main(){
    Solution sol;
    vector<int>prices={7,1,5,3,6,4};
    cout<<sol.maxProfit(prices)<<endl;
}
