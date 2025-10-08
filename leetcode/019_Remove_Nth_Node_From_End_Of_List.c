#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(!head)return head;
    struct ListNode *ans = head;
    int sz = 0,cur = 0;
    while(head){
        sz++;
        head = head->next;
    }
    struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next = ans;
    ans = temp;
    while(cur != (sz-n)){
        cur++;
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return ans->next;
}
int main(){
    return 0;
}

