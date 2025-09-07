#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void dfs(int i,int j,int n,int m,vector<vector<char>>&board,vector<vector<bool>>&vis){
            vector<pair<int,int>>d={{1,0},{-1,0},{0,1},{0,-1}};
            if(board[i][j]=='O' and vis[i][j]==false){
                stack<pair<int,int>>stk;
                stk.push({i,j});
                while(stk.size()){
                    auto [a,b]=stk.top();
                    stk.pop();
                    if(vis[a][b])continue;
                    vis[a][b]=true;
                    for(auto [dx,dy]:d){
                        int x=a+dx,y=b+dy;
                        if(x<0||x==n||y<0||y==m||board[x][y]=='X')continue;
                        if(!vis[x][y])stk.push({x,y});
                    }
                }
            }
        }
        void solve(vector<vector<char>>& board) {
            int n = (int)board.size();
            int m = n?board[0].size():0;
            if(!n||!m)return;
            vector<vector<bool>>vis(n,vector<bool>(m,false));
            for(int i=0;i<n;i++){
                dfs(i,0,n,m,board,vis);
                dfs(i,m-1,n,m,board,vis);
                
            }
            for(int i=0;i<m;i++){
                dfs(0,i,n,m,board,vis);
                dfs(n-1,i,n,m,board,vis);
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(vis[i][j]){
                        board[i][j]='O';
                    }else{
                        board[i][j]='X';
                    }
                }
            }
        }

};
int main(){
    Solution sol;
    vector<vector<char>>board={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    sol.solve(board);
    for(auto i:board){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
