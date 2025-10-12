#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        static const int N = 9;
        int grid[N][N];

        bool isvalid(int x,int y,int number){
            for(int i=0;i<N;i++){

                if(grid[x][i]==number && i!=y)return false;
                if(grid[i][y]==number && i!=x)return false;
            }
            for(int i=(x/3)*3;i<(x/3)*3+3;i++){
                for(int j=(y/3)*3;j<(y/3)*3+3;j++){
                    if(grid[i][j]==number && make_pair(i,j)!=make_pair(x,y)){
                        return false;
                    }
                }
            }
            return true;
        }
        int getDegree(int x,int y){
            vector<bool>pos(10,true);
            for(int i=0;i<N;i++){
                pos[grid[x][i]]=false;
                pos[grid[i][y]]=false;
            }
            for(int i=(x/3)*3;i<(x/3)*3+3;i++){
                for(int j=(y/3)*3;j<(y/3)*3+3;j++){
                    pos[grid[i][j]]=false;
                }
            }
            int ans = 0;
            for(int i=1;i<=N;i++){
                ans+=pos[i];
            }
            return ans;
        }
        pair<int,int> getBestPosition(){
            pair<int,int> best = {-1,-1};
            int Max=10;
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(grid[i][j]==0){
                        int Nax = getDegree(i,j);
                        if(Nax<Max){
                            Max = Nax;
                            best = {i,j};
                        }
                    }
                }
            }
            return best;
        }
        bool solve(){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(grid[i][j]!=0){
                        if(!isvalid(i,j,grid[i][j])){
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        bool isValidSudoku(vector<vector<char>>& board) {
            memset(grid,0,sizeof(grid));
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    grid[i][j]=(board[i][j]=='.')?0:board[i][j]-'0';
                }
            }
            return solve();
        }
};
