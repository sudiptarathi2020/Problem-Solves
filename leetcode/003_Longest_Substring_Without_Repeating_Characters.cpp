#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char,int>mp;
            int back = 0, front = 0;
            int ans = 0,local_ans = 0;
            while(front<(int)s.size()){
                if(mp[s[front]]==0){
                    mp[s[front]]++;
                    local_ans++;
                }else if(mp[s[front]]!=0){
                    while(mp[s[front]]!=0 && back<front){
                        mp[s[back]]--;
                        local_ans--;
                        back++;
                    }
                    mp[s[front]]++;
                    local_ans++;
                }
                ans = max(ans,local_ans);
                front++;
            }
            return ans;
        }
};
int main(){
    Solution sol;
    cout<<sol.lengthOfLongestSubstring("abcabcbb")<<endl;
    cout<<sol.lengthOfLongestSubstring("bbbbb")<<endl;
    cout<<sol.lengthOfLongestSubstring("pwwkew")<<endl;
}
