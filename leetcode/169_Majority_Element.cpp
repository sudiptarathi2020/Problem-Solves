#include <vector>
class Solution {
    public:
        int majorityElement(std::vector<int>& nums) {
            int m,c=0;
            for(int x:nums){
                if(c==0){
                    m=x,c=1;
                }else if(m==x){
                    c++;
                }else{
                    c--;
                }
            }
            return m;
        }
};
