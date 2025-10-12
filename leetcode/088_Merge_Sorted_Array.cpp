#include <vector>
class Solution {
    public:
        void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
            std::vector<int>answer;
            int f=0,s=0;
            while(f<m and s<n){
                if(nums1[f]<=nums2[s]){
                    answer.push_back(nums1[f]);
                    f++;
                }else{
                    answer.push_back(nums2[s]);
                    s++;
                }
            }
            while(f<m){
                answer.push_back(nums1[f]);
                f++;
            }
            while(s<n){
                answer.push_back(nums2[s]);
                s++;
            }
            for(int i=0;i<m+n;i++){
                nums1[i]=answer[i];
            }
        }
};
