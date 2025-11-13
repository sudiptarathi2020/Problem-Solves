#include <stdio.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int countNodes(struct TreeNode* root) {
    if(!root)return 0;
    if(!root->left && !root->right)return 1;
    return countNodes(root->left)+countNodes(root->right)+1;
}
