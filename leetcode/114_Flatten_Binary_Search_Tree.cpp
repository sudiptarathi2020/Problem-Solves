#include<bits/stdc++.h>
#include <queue>
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
        TreeNode* leftRotate(TreeNode* root){
            if(!root||!root->right)return root;
            TreeNode* rightchild = root->right;
            TreeNode* temp = rightchild->left;
            root->right = temp;
            rightchild->left = root;
            return rightchild;
        }
        TreeNode* rightRotate(TreeNode* root){
            if(!root||root->left)return root;
            TreeNode* leftchild = root->left;
            TreeNode* temp = leftchild->right;
            root->left = temp;
            leftchild->right = root;
            return leftchild;
        }
        TreeNode* leftRotationRecursion(TreeNode* root){
            while(root->right){
                root=leftRotate(root);
            }
            if(root->left){
                root->left = leftRotationRecursion(root->left);
            }
            return root;
        }
        TreeNode* rightRotationRecursion(TreeNode* root){
            while(root->left){
                root = rightRotate(root);
            }
            if(root->right){
                root->right = rightRotationRecursion(root->right);
            }
            return root;
        }
        TreeNode* rightSkewed(queue<int>&q){
            if(q.empty())return nullptr;
            TreeNode* child = new TreeNode(q.front());
            q.pop();
            child->right = rightSkewed(q);
            return child;
        }
        void pre_order(TreeNode* root,queue<int>&q){
            if(!root)return;
            q.push(root->val);
            pre_order(root->left,q);
            pre_order(root->right,q);
        }
        void pre_order_print(TreeNode* root,bool left_or_right){
            if(!root){
                cout<<"null"<<" "<<left_or_right<<endl;
                return;
            }
            cout<<root->val<<" "<<left_or_right<<endl;
            pre_order_print(root->left,0);
            pre_order_print(root->right,1);
        }
 
        void flatten(TreeNode* root) {
            queue<int>q;
            pre_order(root,q);
            TreeNode* current = root;
            current->val = q.front();
            q.pop();
            current->left = nullptr;
            while(q.size()){
                current->left = nullptr;
                current->right = new TreeNode(q.front());
                q.pop();
                current= current->right;
            }
            pre_order_print(root,1);
        }

};
int main(){
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    sol.flatten(root);

}
