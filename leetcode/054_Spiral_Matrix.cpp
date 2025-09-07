#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int>ans;
            size_t n = matrix.size();
            size_t m = n?matrix[0].size():0;
            bool vis[n][m];
            memset(vis,0,sizeof vis);
            if(!n||!m)return ans;
            size_t cur_x = 0, cur_y = 0;
            int direction = 0;

            for(size_t i=0;i<n*m;i++){
                ans.push_back(matrix[cur_x][cur_y]);
                vis[cur_x][cur_y]=true;
                if(direction == 0){
                    if(cur_y==m-1 || vis[cur_x][cur_y+1]){
                        direction = 1;
                        cur_x ++;
                    }else{
                        cur_y++;
                    }
                }else if(direction == 1){
                    if(cur_x == n-1 || vis[cur_x+1][cur_y]){
                        direction = 2;
                        cur_y --;
                    }else{
                        cur_x++;
                    }
                }else if(direction == 2){
                    if(cur_y == 0 || vis[cur_x][cur_y-1]){
                        direction = 3;
                        cur_x --;
                    }else{
                        cur_y --;
                    }
                }else{
                    if(cur_x == 0 || vis[cur_x-1][cur_y]){
                        direction = 0;
                        cur_y ++;
                    }else{
                        cur_x --;
                    }
                }
            }
            return ans;
        }
};
int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = sol.spiralOrder(matrix);
    for(auto i:ans)cout<<i<<" ";
}
