#include<stddef.h>
enum bool{
    false, true
};
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
enum bool isValidBST(struct TreeNode* root){
    const int N = 10010;
    struct TreeNode* stack[N];
    int inorder[N];
    int stk_pointer=0,inorder_pointer=0;
    while(stk_pointer!=0||root!=NULL){
        while(root!=NULL){
            stack[stk_pointer++]=root;
            root = root->left;
        }
        root = stack[stk_pointer--];
        inorder[inorder_pointer++]=root->val;
        root = root->right;
    }
    enum bool ans=true;
    for(int i=1;i<inorder_pointer;i++){
        if(inorder[i]<=inorder[i-1]){
            ans = false;
        }
    }
    return ans;
};
int main(){

}
