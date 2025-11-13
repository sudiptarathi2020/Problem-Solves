#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(!root)return false;
    if(!root->left && !root->right && targetSum - root->val == 0){
        return true;
    }
    if(hasPathSum(root->left,targetSum-root->val)==true){
        return true;
    }
    if(hasPathSum(root->right,targetSum-root->val)==true){
        return true;
    }
    return false;
}
