#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void dfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int i,int j,int n,int m){
            vis[i][j]=true;
            cout<<i<<" "<<j<<endl;
            int dx[]={1,-1,0,0};
            int dy[]={0,0,1,-1};
            for(int ii=0;ii<4;ii++){
                int X = dx[ii]+i;
                int Y = dy[ii]+j;
                if(X>=0 and X<n and Y>=0 and Y<m){
                    if(!vis[X][Y] and grid[X][Y]=='1'){
                        dfs(grid,vis,X,Y,n,m);
                    }
                }
            }
        }
        int numIslands(vector<vector<char>>& grid) {
            int n = (int)grid.size();
            int m = n?grid[0].size():0;
            if(!n||!m)return 0;
            int count = 0;
            vector<vector<bool>>vis(n,vector<bool>(m,false));
            for(int i = 0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(vis[i][j]==false and grid[i][j]=='1'){
                        count++;
                        dfs(grid,vis,i,j,n,m);
                        cout<<"----"<<endl;
                    }
                }
            }
            return count;
        }
};
int main(){
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution sol;
    cout<<sol.numIslands(grid)<<endl;
}
