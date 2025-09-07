#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int val;
        vector<Node*> neighbors;
        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
};

class Solution {
    public:
        map<int,Node*>vis;
        Node* cloneGraph(Node* node) {
            if(!node)return nullptr;
            if(vis[node->val])return vis[node->val];
            Node* fakenode = new Node();
            fakenode->val = node->val;
            vis[node->val]=fakenode;
            for(Node* childnode:node->neighbors){
                vis[node->val]->neighbors.push_back(cloneGraph(childnode));
            }
            return vis[node->val];
        }

};
void dfs(Node* node,vector<bool>&vis){
    if(!node)return;
    if(vis[node->val])return;
    vis[node->val]=true;
    cout<<node->val<<" ";
    for(auto it:node->neighbors){
        dfs(it,vis);
    }
}
int main(){
    Node* node = new Node(1);
    node->neighbors.push_back(new Node(2));
    node->neighbors.push_back(new Node(3));
    node->neighbors[0]->neighbors.push_back(node);
    node->neighbors[0]->neighbors.push_back(node->neighbors[1]);
    Solution sol;
    Node* fakenode = sol.cloneGraph(node);
    vector<bool>vis(110,false);
    dfs(fakenode,vis);
}
