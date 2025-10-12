#include <vector>
#include <map>
class Solution {
    public:
        int removeDuplicates(std::vector<int>& nums) {
            std::map<int,int>mp;
            std::vector<int>ans;
            for(int x:nums){
                if(mp[x]==0){
                    ans.push_back(x);
                    mp[x]++;
                }
            }
            int rt=ans.size();
            nums.clear();
            nums.resize(rt);
            for(int i=0;i<rt;i++){
                nums[i]=ans[i];
            }
            return rt;
        }
};
