#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {

    class Node_t{
        public:
            int val;
            int level;
            Node_t* left;
            Node_t* right;
            Node_t* next;
            Node_t() : val(0),level(0), left(NULL), right(NULL), next(NULL) {}

            Node_t(int _val) : val(_val),level(0), left(NULL), right(NULL), next(NULL) {}

            Node_t(int _val, Node_t* _left, Node_t* _right, Node_t* _next)
                : val(_val),level(0), left(_left), right(_right), next(_next) {}

    };
    public:
    void deep_copy(Node* root,Node_t*& fake_root,int level=0){
        if(!root)return;
        fake_root=new Node_t(root->val);
        fake_root->level = level;
        if(root->left){
            deep_copy(root->left,fake_root->left,level+1);
        }
        if(root->right){
            deep_copy(root->right,fake_root->right,level+1);
        }
    }
    void print(Node* fake_root){
        if(fake_root==nullptr)return;
        cout<<fake_root->val<<" ";
        if(fake_root->next!=nullptr){
            cout<<fake_root->next->val;
        }
        cout<<endl;
        print(fake_root->left);
        print(fake_root->right);
    }
    Node* connect(Node* root) {
        Node_t* fake_root=nullptr;
        deep_copy(root,fake_root,0);
        //print(fake_root);
        list<Node_t*> q;
        list<Node*> qq;
        qq.push_back(root);
        q.push_front(fake_root);
        while(q.size()){
            Node_t* v= q.back();
            q.pop_back();
            if(!v)continue;
            Node* vv = qq.back();
            qq.pop_back();
            if(v->right && vv->right){
                if(!q.empty() && v->right->level==q.front()->level){
                    v->right->next = q.front();
                    vv->right->next = qq.front();
                }
                q.push_front(v->right);
                qq.push_front(vv->right);
            }
            if(v->left && vv->left){
                if(!q.empty() && v->left->level==q.front()->level){
                    v->left->next = q.front();
                    vv->left->next = qq.front();
                }
                q.push_front(v->left);
                qq.push_front(vv->left);
            }
        }
        //cout<<endl;
        //deep_copy(fake_root,root);
        //print(root);
        return root;
    }

};
