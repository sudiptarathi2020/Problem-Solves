#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
    public:
        int hIndex(vector<int>& citations) {
            int ans = 0;
            sort(citations.begin(),citations.end());
            for(int i=0;i<=(int)citations.size();i++){
                auto it = lower_bound(citations.begin(),citations.end(),i);
                int n = citations.end()-it;
                if(n>=i){
                    ans = max(ans,i);
                }
            }
            return ans;
        }
};
int main(){
    Solution sol;
    vector<int>citations{3,0,6,1,5};
    cout<<sol.hIndex(citations)<<endl;
}
