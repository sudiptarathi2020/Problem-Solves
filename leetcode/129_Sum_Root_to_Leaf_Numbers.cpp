#include <algorithm>
#include<bits/stdc++.h>
#include <cstddef>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct FakeNode {
    int val;
    FakeNode *left;
    FakeNode *right;
    FakeNode *parent;
    FakeNode() : val(0), left(nullptr), right(nullptr) {}
    FakeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    FakeNode(int x, FakeNode *left, FakeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    public:
        vector<FakeNode*> leafs;
        void copy(TreeNode* root,FakeNode*& fakeroot,FakeNode* fparent){
            if(!root)return;
            fakeroot = new FakeNode(root->val);
            fakeroot->parent = fparent;
            if(root->left)copy(root->left,fakeroot->left,fakeroot);
            if(root->right)copy(root->right,fakeroot->right,fakeroot);
            if(!fakeroot->left && !fakeroot->right){
                leafs.push_back(fakeroot);
            }
        }
        int sumNumbers(TreeNode* root) {
            FakeNode* fakeroot = nullptr;
            copy(root,fakeroot,nullptr);
            int ans = 0;
            for(FakeNode* fakenode: leafs){
                int current_ans = 0;
                int x = 1;
                while(fakenode!=nullptr){
                    current_ans += x* fakenode->val;
                    x*=10;
                    fakenode=fakenode->parent;
                }
                ans+=current_ans;
            }
            return ans;
        }
};
int main(){

}
