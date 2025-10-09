#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int lvl=0;
void dfs(struct TreeNode *root,int l){
    if(!root)return;
    if(lvl<l)lvl = l;
    dfs(root->left,l+1);
    dfs(root->right,l+1);
}
void dfs1(struct TreeNode *root,int arr[],int index){
    if(!root)return;
    if(arr[index]==-200){
        arr[index]=root->val;
    }
    dfs1(root->right,arr,index+1);
    dfs1(root->left,arr,index+1);

}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if(!root){
        *returnSize = 0;
        return NULL;
    };
    lvl = 0;
    dfs(root,1);
    *returnSize = lvl;
    int *arr = (int*)malloc(lvl*sizeof(int));
    for(int i=0;i<lvl;i++)arr[i]=-200;
    dfs1(root,arr,0);
    return arr;
}



