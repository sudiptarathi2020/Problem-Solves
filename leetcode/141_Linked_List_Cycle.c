#include<stdbool.h>
#include <string.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
bool hasCycle(struct ListNode *head) {
    int M = 1e7;
    while(head){
        if(head->val == M ){
            return true;
        }
        head->val = M;
        if(head->next != NULL){
            head = head->next;
        }else{
            break;
        }
    }
    return false;
}
int main(){
    return 0;
}

