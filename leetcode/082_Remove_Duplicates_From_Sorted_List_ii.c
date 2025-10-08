#include<stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *tail = &dummy;
    struct ListNode *cur = head;
    while(cur){
        int cnt = 1;
        while(cur->next && cur->val == cur->next->val){
            cnt++;
            cur = cur->next;
        }
        if(cnt == 1){
            struct ListNode *x = (struct ListNode*)malloc(sizeof(struct ListNode));
            x->val = cur->val;
            x->next = NULL;
            tail->next = x;
            tail = tail->next;
        }
        cur = cur->next;
    }
    return dummy.next;
}
int main(){
    return 0;
}

