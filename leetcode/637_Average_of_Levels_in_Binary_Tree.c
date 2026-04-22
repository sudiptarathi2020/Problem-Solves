#include <stdlib.h>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode *root, int curLevel, int *returnSize)
{
    if (!root)
        return;

    *returnSize = curLevel + 1 > *returnSize ? curLevel + 1 : *returnSize;

    dfs(root->left, curLevel + 1, returnSize);
    dfs(root->right, curLevel + 1, returnSize);
}

void get_ans_dfs(struct TreeNode *root, int curLevel, double *ans, int *cnt)
{
    if (!root)
        return;

    ans[curLevel] += (double)root->val;
    cnt[curLevel] += 1;

    get_ans_dfs(root->left, curLevel + 1, ans, cnt);
    get_ans_dfs(root->right, curLevel + 1, ans, cnt);

}

double* averageOfLevels(struct TreeNode* root, int* returnSize) 
{
    double *ans;
    int *cnt;
    int i;

    *returnSize = 0;

    dfs(root, 0, returnSize);

    ans = malloc(sizeof(double) * (*returnSize));
    cnt = malloc(sizeof(int) * (*returnSize));

    for (i = 0; i < *returnSize; i++)
    {
        ans[i] = 0;
        cnt[i] = 0;
    }

    get_ans_dfs(root, 0, ans, cnt);

    for (i = 0; i < *returnSize; i++)
    {
        ans[i] /= cnt[i];
    }

    free(cnt);

    return ans;
}
