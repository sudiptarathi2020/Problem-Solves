#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        static const int N = 9;
        int grid[N][N];
        struct position{
            int x,y;
            vector<int>possible_numbers;
            position(int _x,int _y,vector<int>_possible_numbers){
                x=_x,y=_y,possible_numbers=_possible_numbers;
            }

            bool operator<(const position& other) const {
                return possible_numbers.size() < other.possible_numbers.size();
            }
        };
        vector<int> degree(int x,int y){
            vector<int>empt;
            vector<bool>possible(10,true);
            for(int i=0;i<N;i++){
                if(grid[x][i]!=0){
                    possible[grid[x][i]]=false;
                }
                if(grid[i][y]!=0){
                    possible[grid[i][y]]=false;
                }
            }
            for(int i=(x/3)*3;i<(x/3)*3+3;i++){
                for(int j=(y/3)*3;j<(y/3)*3+3;j++){
                    if(grid[i][j]!=0){
                        possible[grid[i][j]]=false;
                    }
                }
            }
            for(int i=1;i<10;i++){
                if(possible[i])empt.push_back(i);
            }
            return empt;
        }
        vector<position>arr;
        bool isvalid(int x,int y,int number){
            for(int i=0;i<N;i++){
                if(grid[x][i]==number || grid[i][y]==number)return false;
            }
            for(int i=(x/3)*3;i<(x/3)*3+3;i++){
                for(int j=(y/3)*3;j<(y/3)*3+3;j++){
                    if(grid[i][j]==number){
                        return false;
                    }
                }
            }
            return true;
        }
        bool solve(int cnt){
            if(cnt==(int)arr.size()){
                return true;
            }
            position P = arr[cnt];
            for(int x: P.possible_numbers){
                if(isvalid(P.x,P.y,x)){
                    grid[P.x][P.y]=x;
                    //cout<<" x: "<<P.x<<" y: "<<P.y<< " : x"<<endl;
                    if(solve(cnt+1)){
                        return true;
                    }
                    grid[P.x][P.y]=0;
                }
            }
            return false;
        }
        void solveSudoku(vector<vector<char>>& board) {
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    grid[i][j]=board[i][j]=='.'?0:board[i][j]-'0';
                }
            }
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(grid[i][j]==0){
                        arr.push_back(position(i,j,degree(i,j)));
                    }
                }
            }
            vector<vector<char>> ans(N);
            sort(arr.begin(),arr.end());
            if(solve(0)){
                for(int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                        ans[i].push_back(grid[i][j]);
                        board[i][j]= grid[i][j]==0?'.':grid[i][j]+'0';
                    }
                }
            }
        }
};
