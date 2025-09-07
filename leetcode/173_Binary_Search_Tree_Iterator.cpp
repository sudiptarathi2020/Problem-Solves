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
class BSTIterator {
    public:
        int N;
        int curr;
        vector<int>order;
        BSTIterator(TreeNode* root) {
            stack<TreeNode*>stk;
            while(stk.size()||root){
                while(root){
                    stk.push(root);
                    root = root->left;
                }
                root = stk.top();
                stk.pop();
                order.push_back(root->val);
                root = root->right;
            }
            N = (int)order.size();
            curr = -1;
        }

        int next() {
            curr++;
            return order[curr];
        }

        bool hasNext() {
            if(curr+1<N)return true;
            return false;
        }
};
int main(){

}
