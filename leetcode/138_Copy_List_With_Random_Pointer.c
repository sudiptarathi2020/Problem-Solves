#include <stdlib.h>
struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct Node* copyRandomList(struct Node* head) {
    int N = 1001,cur = 0,i,j;
    struct Node *A[N],*B[N];
    struct Node* temp = head;
    if(!temp){
        return NULL;
    }
    while(temp){
        struct Node *t = (struct Node*)malloc(sizeof(struct Node));
        t->val = temp->val;
        t->next = t->random = NULL;
        A[cur]=temp;
        B[cur]=t;
        if(cur>0){
            B[cur-1]->next = B[cur];
        }
        cur++;
        temp = temp->next;
    }
    for(i=0;i<cur;i++){
        for(j=0;j<cur;j++){
            if(A[i]->random == A[j]){
                B[i]->random = B[j];
                break;
            }
        }
    }
    return B[0];
}
int main(){
    return 0;
}

