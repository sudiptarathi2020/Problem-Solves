#include <vector>
class Solution {
    public:
        int removeElement(std::vector<int>& nums, int val) {
            int ans=0;
            std::vector<int>answer_array;
            for(int x:nums){
                if(x!=val){
                    ans++;
                    answer_array.push_back(x);
                }
            }
            nums.clear();
            nums.resize(ans);
            for(int i=0;i<(int)answer_array.size();i++){
                nums[i]=answer_array[i];
            }
            return ans;
        }
};
