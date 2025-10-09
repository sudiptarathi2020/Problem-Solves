#include<stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void dfs(struct TreeNode *root,int *lvl_count,int cur_level_depth){
    if(!root)return;
    if(*lvl_count < cur_level_depth + 1)*lvl_count = cur_level_depth+1;
    dfs(root->left, lvl_count, cur_level_depth + 1);
    dfs(root->right, lvl_count, cur_level_depth + 1);
}
void dfs1(struct TreeNode *root,int **returnColumnSizes,  int cur_level){
    if(!root)return;
    (*returnColumnSizes)[cur_level]++;
    dfs1(root->left,returnColumnSizes,cur_level+1);
    dfs1(root->right,returnColumnSizes,cur_level+1);
}
void dfs2(struct TreeNode *root,int **ans,int *index,int cur_level){
    if(!root)return;
    ans[cur_level][index[cur_level]] = root->val;
    index[cur_level]++;
    dfs2(root->left,ans,index,cur_level+1);
    dfs2(root->right,ans,index,cur_level+1);
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(!root){
        *returnSize = 0;
        return NULL;
    }
    int lvl_count = 0;
    dfs(root,&lvl_count,0);
    *returnSize = lvl_count;
    *returnColumnSizes = (int*)malloc(lvl_count*sizeof(int));
    for(int i=0;i<lvl_count;i++){
        (*returnColumnSizes)[i]=0;
    }
    dfs1(root,returnColumnSizes,0);
    int *index = (int*)malloc(sizeof(int)*lvl_count);
    int **ans = (int**)malloc(lvl_count * sizeof(int*));
    for(int i = 0;i<lvl_count;i++){
        ans[i]=(int*)malloc((*returnColumnSizes)[i]*sizeof(int));
        index[i]=0;
    }
    dfs2(root,ans,index,0);
    free(index);
    return ans;
}


