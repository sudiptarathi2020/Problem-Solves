#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* ans, dummy;
    ans = &dummy;
    dummy.next = NULL;
    while(list1 && list2){
        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next = NULL;
        if(list1->val < list2->val){
            temp->val = list1->val;
            list1=list1->next;
        }else{
            temp->val = list2->val;
            list2=list2->next;
        }
        ans->next = temp;
        ans = temp;
    }
    while(list1){
        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next = NULL;
        temp->val = list1->val;
        list1=list1->next;
        ans->next = temp;
        ans = temp;
    }
    while(list2){
        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next = NULL;
        temp->val = list2->val;
        list2=list2->next;
        ans->next = temp;
        ans = temp;
    }
    return dummy.next;
}
int main(){
}

