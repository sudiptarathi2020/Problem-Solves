#include<vector>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
    public:
        int value;
        BinaryTree* left;
        BinaryTree* right;

        BinaryTree(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};
void branch_sum(BinaryTree *root,vector<int>&ans,int sum){
    if(!root)return;
    if(!root->left && !root->right){
        ans.push_back(sum+root->value);
    }else{
        branch_sum(root->left,ans,sum+root->value);
        branch_sum(root->right,ans,sum+root->value);
    }
}

vector<int> branchSums(BinaryTree* root) {
    // Write your code here.
    vector<int>ans;
    branch_sum(root,ans,0);
    return ans;
}
