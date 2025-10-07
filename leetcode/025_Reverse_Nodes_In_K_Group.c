struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(!head)return head;
    int N = 5001,cur=0;
    struct ListNode *A[N];
    while(head){
        A[cur] = head;
        if(cur>0){
            A[cur-1]->next = A[cur];
        }
        cur++;
        head = head->next;
    }
    N = cur,cur=0;
    while(k<=(N-cur)){
        int start = cur,end = cur+k-1;
        if(2*k<=(N-cur)){
            A[cur]->next = A[end+k];
        }else{
            A[cur]->next = A[end]->next;
        }
        for(int i=end;i>start;i--){
            A[i]->next = A[i-1];
        }
        cur = cur+k;
    }
    return A[k-1];
}
int main(){
    return 0;
}

