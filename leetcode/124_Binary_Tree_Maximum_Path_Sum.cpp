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
struct FakeNode {
    int val;
    int a,b;
    FakeNode *left;
    FakeNode *right;
    FakeNode() : val(0),a(0),b(0), left(nullptr), right(nullptr) {}
    FakeNode(int x) : val(x),a(x),b(x), left(nullptr), right(nullptr) {}
    FakeNode(int x, FakeNode *left, FakeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        void copy(TreeNode* root,FakeNode*& fakeroot){
            if(!root)return;
            fakeroot = new FakeNode(root->val);
            if(root->left)copy(root->left,fakeroot->left);
            if(root->right)copy(root->right,fakeroot->right);
        }
        void dfs(FakeNode*& fakeroot,int* ans){
            if(!fakeroot->left && !fakeroot->right){
                *ans = max(max(*ans,fakeroot->a),fakeroot->b);
                return;
            }
            if(fakeroot->left){
                dfs(fakeroot->left,ans);
                fakeroot->a = max(fakeroot->a,fakeroot->left->a+fakeroot->val);
                fakeroot->b = max(fakeroot->b,fakeroot->left->a+fakeroot->b);
            }
            if(fakeroot->right){
                dfs(fakeroot->right,ans);
                fakeroot->a = max(fakeroot->a,fakeroot->right->a+fakeroot->val);
                fakeroot->b = max(fakeroot->b,fakeroot->right->a+fakeroot->b);
            }
            *ans = max(max(*ans,fakeroot->a),fakeroot->b);
        }
        int maxPathSum(TreeNode* root) {
            FakeNode* fakeroot = nullptr;
            copy(root,fakeroot);
            int ans = fakeroot->val;;
            dfs(fakeroot,&ans);
            return ans;
        }
};
int main(){

}
