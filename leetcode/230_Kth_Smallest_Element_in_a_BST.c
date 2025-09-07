#include<stdio.h>
#include<stddef.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int kthSmallest(struct TreeNode* root, int k) {
    int N = 10010;
    struct TreeNode* stk[N];
    int inorder[N];
    int stk_pointer = 0;
    int inorder_pointer = 0;
    while(stk_pointer != 0 || root!=NULL){
        while(root!=NULL){
            stk[stk_pointer++]=root;
            root=root->left;
        }
        root = stk[--stk_pointer];
        inorder[inorder_pointer++]=root->val;
        root= root->right;
    }
    return inorder[k-1];
}
int main(){
    struct TreeNode a,b,c,d,e,f;
    a.val=5; a.left=&b; a.right=&c;
    b.val=3; b.left=&d; b.right=&e;
    c.val=6; c.left=NULL; c.right=NULL;
    d.val=2; d.left=&f; d.right=NULL;
    e.val=4; e.left=NULL; e.right=NULL;
    f.val=1; f.left=NULL; f.right=NULL;
    int k=3;
    int res = kthSmallest(&a,k);
    printf("%d\n",res);
}
