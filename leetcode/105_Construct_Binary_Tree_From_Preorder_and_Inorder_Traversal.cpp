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
class Solution {
    public:
        vector<int>pre_copy, in_copy;
        unordered_map<int,int>inorder_index;
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            pre_copy = preorder;
            in_copy = inorder;
            int val= preorder[0];
            TreeNode* root= new TreeNode(val);
            int vec_sz=(int)preorder.size();
            //assert(vec_sz==(int)inorder.size());
            if(vec_sz==1){
                return root;
            }
            for(int i=0;i<vec_sz;i++){
                inorder_index[inorder[i]]=i;
            }
            /*
               cout<<"-----------\n\n";
               cout<<"root: "<<val<<endl;
               cout<<"preorder: ";print_vector(preorder);
               cout<<"inorder: ";print_vector(inorder);
               cout<<"left preorder: ";print_vector(left_preorder);
               cout<<"left inorder: ";print_vector(left_inorder);
               cout<<"right preorder: ";print_vector(right_preorder);
               cout<<"right inorder: ";print_vector(right_inorder);
               cout<<"-----------\n\n";
               */

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
                root->left=buildTreeHelper(pre_start+1,pre_start+left_count,in_start,left_in_end);
                root->right=buildTreeHelper(pre_start+left_count+1,pre_start+left_count+right_count,right_in_start,in_end);
            }else if(left_count>0){
                root->left = buildTreeHelper(pre_start+1,pre_start+left_count,in_start,left_in_end);
            }else if(right_count>0){
                root->right = buildTreeHelper(pre_start+1,pre_start+right_count,right_in_start,in_end);
            }
            return root;
        }


};
