#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            list<int>lst;
            for(int num:nums){
                lst.push_back(num);
            }
            while(k--){
                int num=lst.back();
                lst.pop_back();
                lst.push_front(num);
            }
            nums.clear();
            for(int num:lst){
                nums.push_back(num);
            }
        }
};
