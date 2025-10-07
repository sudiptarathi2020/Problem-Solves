#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(!head)return NULL;
    left--,right--;
    int N = 501,cur=0;
    struct ListNode *A[N];
    while(head){
        A[cur]=head;
        if(cur>0){
            A[cur-1]->next=A[cur];
        }
        cur++;
        head = head->next;
    }
    while(left<right){
        int t = A[left]->val;
        A[left]->val = A[right]->val;
        A[right]->val = t;
        left++,right--;
    }
    return A[0];
}
int main(){
    return 0;
}

