#include <vector>
class Solution {
    public:
        int removeDuplicates(std::vector<int>& nums) {
            int iter = 0, idx = 0;
            while(iter < nums.size()){
                int count = 0;
                while(iter+1 < nums.size() && nums[iter] == nums[iter+1]){
                    count++;
                    iter++;
                }
                if(count >= 1){
                    nums[idx++] = nums[iter];
                    nums[idx++] = nums[iter];
                }else{
                    nums[idx++] = nums[iter];
                }
                iter++;
            }
            return idx;

        }
};
