#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> ans;
            for(int i=0;i<(1<<n);i++){
                if(__builtin_popcount(i)==k){
                    vector<int> temp;
                    for(int j=0;j<n;j++){
                        if(i&(1<<j)){
                            temp.push_back(j+1);
                        }
                    }
                    ans.push_back(temp);
                }
            }
            return ans;
        }
};
