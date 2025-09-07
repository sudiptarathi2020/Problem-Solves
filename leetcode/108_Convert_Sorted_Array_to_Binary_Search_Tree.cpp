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
        struct Node {
            int val;
            int height;
            Node *left;
            Node *right;
            Node() : val(0),height(1), left(nullptr), right(nullptr) {}
            Node(int x) : val(x),height(1), left(nullptr), right(nullptr) {}
            Node(int x, Node *left, Node *right) : val(x),height(1), left(left), right(right) {}
        };
        Node* rightRotate(Node* root){
            Node* temp;
            temp = root->left;
            Node* R = temp->right;
            temp->right = root;
            root->left = R;
            root->height = max(root->left?root->left->height:0,root->right?root->right->height:0)+1;
            temp->height = max(temp->left?temp->left->height:0,temp->right?temp->right->height:0)+1;
            return temp;
        }
        Node* leftRotate(Node* root){
            Node* temp;
            temp=root->right;
            Node* L = temp->left;
            temp->left = root;
            root->right = L;
            root->height = max(root->left?root->left->height:0,root->right?root->right->height:0)+1;
            temp->height = max(temp->left?temp->left->height:0,temp->right?temp->right->height:0)+1;
            return temp;
        }
        Node* fixBalance(Node* root){
            int left_height = root->left?root->left->height:0;
            int right_height = root->right?root->right->height:0;
            if(left_height-right_height>1){
                int left_child_left_height = root->left->left?root->left->left->height:0;
                int left_child_right_height = root->left->right?root->left->right->height:0;
                if(left_child_left_height>=left_child_right_height){
                    root = rightRotate(root);
                }else if(left_child_right_height>left_child_left_height){
                    root->left = leftRotate(root->left);
                    root = rightRotate(root);
                }
            }else if(right_height-left_height>1){
                int right_child_left_height=root->right->left?root->right->left->height:0;
                int right_child_right_height = root->right->right?root->right->right->height:0;
                if(right_child_right_height>=right_child_left_height){
                    root=leftRotate(root);
                }else if(right_child_right_height<right_child_left_height){
                    root->right=rightRotate(root->right);
                    root=leftRotate(root);
                }
            }
            root->height = max(root->left?root->left->height:0,root->right?root->right->height:0)+1;
            return root;
        }
        Node* insert(Node* root,int val){
            if(root==nullptr){
                return new Node(val);
            }else{
                if(val<root->val){
                    root->left = insert(root->left,val);
                }else if(val>root->val){
                    root->right = insert(root->right,val);
                }
                return fixBalance(root);
            }
        }
        void inorder(Node* root){
            if(!root)return;
            if(root->left)inorder(root->left);
            cout<<"Node Value: "<<root->val<<" , "<<"Node Height: "<<root->height<<endl;
            if(root->right)inorder(root->right);
        }

        void deepCopy(Node* x,TreeNode*& y){
            if(!x)return;
            y = new TreeNode(x->val);
            deepCopy(x->left,y->left);
            deepCopy(x->right,y->right);
        }
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            Node* root = nullptr;
            for(int num:nums){
                root=insert(root,num);
            }
            inorder(root);
            TreeNode* y=nullptr;
            deepCopy(root,y);
            return y;
            inorder(root);
        }

};
int main(){
    Solution sol;
    vector<int>nums={1,2,3,4,5,6,7,8,9};
    sol.sortedArrayToBST(nums);
}
