#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct NodePtrHash {
    size_t operator()(const TreeNode* n) const noexcept {
        return std::hash<const TreeNode*>()(n);
    }
};
struct NodePtrEq {
    bool operator()(const TreeNode* a, const TreeNode* b) const noexcept {
        return a == b;
    }
};class Solution {
    void dfs(TreeNode* root,TreeNode* parent,unordered_map<TreeNode*,int,NodePtrHash, NodePtrEq>&intime,unordered_map<TreeNode*,int,NodePtrHash, NodePtrEq>&outtime,int& time,unordered_map<TreeNode*,vector<TreeNode*>,NodePtrHash, NodePtrEq>&father){
        intime[root]=time++;
        father[root].resize(18);
        father[root][0]=parent;
        for(int i=1;i<18;i++){
            if(father[root][i-1]!=nullptr){
                father[root][i]=father[father[root][i-1]][i-1];
            }else{
                father[root][i]=nullptr;
            }
        }
        if(root->left)dfs(root->left,root,intime,outtime,time,father);
        if(root->right)dfs(root->right,root,intime,outtime,time,father);
        outtime[root]=++time;
    }
    bool is_ancestor(TreeNode* u,TreeNode* v,unordered_map<TreeNode*,int,NodePtrHash, NodePtrEq>&intime,unordered_map<TreeNode*,int,NodePtrHash, NodePtrEq>&outtime){
        if(!u||!v)return false;
        return intime[u]<=intime[v] && outtime[u]>=outtime[v];
    }
    TreeNode* lca(TreeNode* u,TreeNode* v,unordered_map<TreeNode*,int,NodePtrHash, NodePtrEq>&intime,unordered_map<TreeNode*,int,NodePtrHash, NodePtrEq>&outtime,unordered_map<TreeNode*,vector<TreeNode*>,NodePtrHash, NodePtrEq>&father){
        if(is_ancestor(u,v,intime,outtime))return u;
        if(is_ancestor(v,u,intime,outtime))return v;
        for(int i=17;i>=0;i--){
            if(father[u][i]!=nullptr && !is_ancestor(father[u][i],v,intime,outtime)){
                u=father[u][i];
            }
        }
        return father[u][0];
    }
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            unordered_map<TreeNode*,int,NodePtrHash, NodePtrEq>intime,outtime;
            unordered_map<TreeNode*,vector<TreeNode*>,NodePtrHash, NodePtrEq>father;
            int time = 0;
            dfs(root,nullptr,intime,outtime,time,father);
            return lca(p,q,intime,outtime,father);
        }
};
int main(){

}
