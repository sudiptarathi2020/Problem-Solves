#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool exist(int x,int y,vector<vector<char>>& board, string word,int idx=0,long long mask=0){
        if(x<0||x==(int)board.size()||y<0||y==(int)board[0].size())return false;
        int k = 7 * x + y;
        if(mask&(1<<k))return false;
        mask = mask | (1<<k);
        if(idx==(int)word.size())return true;

        if(idx==(int)word.size()-1&&board[x][y]==word[idx])return true;
        if(board[x][y]!=word[idx])return false;
        if(exist(x+1,y,board,word,idx+1,mask)){
            return true;
        }
        if(exist(x-1,y,board,word,idx+1,mask)){
            return true;
        }
        if(exist(x,y+1,board,word,idx+1,mask)){
            return true;
        }
        if(exist(x,y-1,board,word,idx+1,mask)){
            return true;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = (int)board.size();
        int m = n?(int)board[0].size():0;
        if(!n||!m)return false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(exist(i,j,board,word)){
                    return true;
                }
            }
        }
        return false;
    }

};
int main(){
    Solution sol;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    cout << (sol.exist(board, word) ? "true" : "false") << endl; // Output: true
    return 0;
}
