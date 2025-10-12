#include <cstdlib>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int max(int a,int b){
    return a>b?a:b;
}
class Solution {
    public:
        int n=true;
        bool isBalanced(TreeNode* root) {
            int ans= isbal(root);
            return n;     
        }
        int isbal(TreeNode* root){
            if(root== nullptr){
                return 0;
            }
            int lh = isbal(root->left);
            int rh = isbal(root->right);
            if (abs(lh-rh)>1){
                n=false;
            }
            return max(lh,rh)+1;
        }
};
