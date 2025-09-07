#include<bits/stdc++.h>
#include <cstdio>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2;
        while(l1){
            v1.push_back(l1->val);
            l1=l1->next;
        }
        reverse(v1.begin(),v1.end());
        while(l2){
            v2.push_back(l2->val);
            l2=l2->next;
        }
        reverse(v2.begin(),v2.end());
        vector<int>ans;
        int rem=0;
        while(v1.size()&&v2.size()){
            int last = v1.back()+v2.back()+rem;
            v1.pop_back(),v2.pop_back();
            if(last>=10){
                ans.push_back(last%10);
                rem= last/10;
            }else{
                ans.push_back(last);
                rem = 0;
            }
        }
        while(v1.size()){
            int last = v1.back()+rem;
            v1.pop_back();
            if(last>=10){
                ans.push_back(last%10);
                rem= last/10;
            }else{
                ans.push_back(last);
                rem = 0;
            }
        }
        while(v2.size()){
            int last = v2.back()+rem;
            v2.pop_back();
            if(last>=10){
                ans.push_back(last%10);
                rem= last/10;
            }else{
                ans.push_back(last);
                rem = 0;
            }
        }
        if(rem)ans.push_back(rem);
        ListNode dummy;
        ListNode* curr = &dummy;
        for (int x : ans) {
            curr->next = new ListNode(x);
            curr = curr->next;
        }
        return dummy.next;
    }

};
void print(ListNode* root){
    if(!root)return;
    cout<<root->val<<endl;
    print(root->next);
}
int main(){
    ListNode* l1=new ListNode(2);
    l1->next=new ListNode(4);
    l1->next->next=new ListNode(3);
    ListNode* l2=new ListNode(5);
    l2->next=new ListNode(6);
    l2->next->next=new ListNode(4);

    Solution sol;
    ListNode* ans_node = sol.addTwoNumbers(l1,l2);
    print(ans_node);
}
