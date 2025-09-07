#include <algorithm>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            ans.push_back(nums);
            while(next_permutation(nums.begin(),nums.end())){
                ans.push_back(nums);
            }
            return ans;
        }
};
void printvector(vector<vector<int>>& ans){
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int main(){
    Solution s;
    vector<int> nums={1,2,3};
    vector<vector<int>> ans=s.permute(nums);
    printvector(ans);
    return 0;
}
