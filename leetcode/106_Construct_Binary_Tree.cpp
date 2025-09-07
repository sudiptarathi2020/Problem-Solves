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
void preorder_print(TreeNode* root){
    if(root==nullptr)return;
    cout<<root->val<<", ";
    preorder_print(root->left);
    preorder_print(root->right);
}
void inorder_print(TreeNode* root){
    if(root==nullptr)return;
    inorder_print(root->left);
    cout<<root->val<<", ";
    inorder_print(root->right);
}
void postorder_print(TreeNode* root){
    if(root==nullptr)return;
    postorder_print(root->left);
    postorder_print(root->right);
    cout<<root->val<<", ";
}
void print_vector(vector<int>vec){
    cout<<endl;
    for(int value:vec){
        cout<<value<<", ";
    }
    cout<<endl;
}
class Solution {
    public:
        vector<int>pre_copy, in_copy;
        unordered_map<int,int>inorder_index;
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            pre_copy = postorder;
            in_copy = inorder;
            int val= postorder[0];
            TreeNode* root= new TreeNode(val);
            int vec_sz=(int)postorder.size();
            //assert(vec_sz==(int)inorder.size());
            if(vec_sz==1){
                return root;
            }
            for(int i=0;i<vec_sz;i++){
                inorder_index[inorder[i]]=i;
            }
            return buildTreeHelper(0,vec_sz-1,0,vec_sz-1);
        }
        TreeNode* buildTreeHelper(int pre_start,int pre_end,int in_start,int in_end) {
            int val= pre_copy[pre_start];
            TreeNode* root= new TreeNode(val);
            int vec_sz=in_end-in_start+1;
            if(vec_sz==1){
                return root;
            }
            int mid = inorder_index[val];
            int left_in_end = mid-1;
            int right_in_start = mid+1;
            int left_count = left_in_end-in_start+1;
            int right_count = in_end -right_in_start+1;
            if(left_count>0 and right_count>0){
                root->right=buildTreeHelper(pre_start+1,pre_start+left_count,in_start,left_in_end);
                root->left=buildTreeHelper(pre_start+left_count+1,pre_start+left_count+right_count,right_in_start,in_end);
            }else if(left_count>0){
                root->right = buildTreeHelper(pre_start+1,pre_start+left_count,in_start,left_in_end);
            }else if(right_count>0){
                root->left = buildTreeHelper(pre_start+1,pre_start+right_count,right_in_start,in_end);
            }
            return root;
        }

};
int main(){
    Solution sol;
    int n;cin>>n;
    vector<int>postorder(n),inorder(n);
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }
    for(int i=0;i<n;i++){
        cin>>postorder[i];
    }
    TreeNode* root = sol.buildTree(inorder,postorder);
    preorder_print(root);cout<<endl;
    inorder_print(root);cout<<endl;
    postorder_print(root);cout<<endl;
}

