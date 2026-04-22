#include <stdbool.h>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode *root) 
{
    if (!root)
        return root;

    struct TreeNode *temp = {0};
    temp = root->left;
    root->left = root->right;
    root->right = temp;

    if (root->left)
        invertTree(root->left);

    if (root->right)
        invertTree(root->right);

    return root;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
    if (p && q)
    {
        if (p->val == q->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else 
        {
            return false;
        }
    }
    else if ((p && !q) || (!p && q))
    {
        return false;
    }
    else 
    {
        return true;
    }
}

bool isSymmetric(struct TreeNode* root) {
    return isSameTree(root->left, invertTree(root->right));
}
