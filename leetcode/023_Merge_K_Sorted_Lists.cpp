#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
    public:
        ListNode* merge(ListNode* l,ListNode* r){
            if(!l)return r;
            if(!r)return l;
            ListNode dummy(0);
            ListNode* tail = &dummy;
            while(l && r){
                if(l->val<=r->val){
                    tail->next = l;
                    l=l->next;
                }else{
                    tail->next=r;
                    r=r->next;
                }
                tail = tail->next;
            }
            tail->next = l?l:r;
            return dummy.next;
        }
        void build(int N,int start,int end,vector<ListNode*>&tree,vector<ListNode*>&lists){
            if(start==end){
                tree[N]=lists[start];
            }else{
                int mid = (start+end)>>1;
                build(N<<1,start,mid,tree,lists);
                build(1|(N<<1),mid+1,end,tree,lists);
                tree[N]=merge(tree[N<<1],tree[1|(N<<1)]);
            }
        }
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(lists.size()==0)return nullptr;
            if(lists.size()==1)return lists[0];
            size_t n = lists.size();
            vector<ListNode*>tree(n<<2);
            build(1,0,n-1,tree,lists);
            return tree[1];
        }
        void print(ListNode* head){
            while(head){
                cout<<head->val<<" ";
                head=head->next;
            }
            cout<<endl;
        }

};
int main(){
    Solution sol;
    vector<ListNode*>lists;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    lists.push_back(l1);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    lists.push_back(l2);
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);
    lists.push_back(l3);
    ListNode* root = sol.mergeKLists(lists);
    sol.print(root);
}
