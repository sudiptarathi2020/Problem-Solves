#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    public:
        vector<pair<int,pair<int,bool>>>arr;
        int kthLargestPerfectSubtree(TreeNode* root, int k) {
            arr.clear();
            dfs(root);
            sort(arr.begin(),arr.end(),[](auto a,auto b){
                    return a.first>b.first;
                    });
            if(size_t(k)>arr.size()){
                return -1;
            }else{
                return arr[k-1].first;
            }
        }
        pair<int,pair<int,bool>> dfs(TreeNode* root){
            if(root==nullptr){
                return {0,{-1,true}};
            }
            if(root->left==nullptr && root->right==nullptr){
                arr.push_back({1,{root->val,true}});
                //cout<<"root: "<<root->val<<", size: "<<1<<", perfect\n";
                return {1,{root->val,true}};
            }
            pair<int,pair<int,bool>> L = dfs(root->left);
            pair<int,pair<int,bool>> R = dfs(root->right);
            if(L.first == R.first and L.second.second == R.second.second and L.second.second == true){
                arr.push_back({L.first+R.first+1,{root->val,true}});
                //cout<<"root: "<<root->val<<", size: "<<L.first+R.first+1<<", perfect\n";
                return {L.first+R.first+1,{root->val,true}};
            }else{
                return {L.first+R.first+1,{root->val,false}};
            }
        }
};
