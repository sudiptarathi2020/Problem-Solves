#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct Node{
    struct TreeNode *val;
    struct Node *prev;
    struct Node *next;
}node;
typedef struct List{
    int sz;
    node *head;
    node *tail;
}list;
void push_front(list **l,struct TreeNode *n){
    if(*l == NULL){
        *l = (list*)malloc(sizeof(list));
        (*l)->sz = 0;
        (*l)->head = (*l)->tail = NULL;
    }
    node *temp = (node*)malloc(sizeof(node));
    temp->val = n;
    temp->prev = NULL;
    temp->next = (*l)->head;
    if((*l)->head){
        (*l)->head->prev = temp;
    }else{
        (*l)->tail = temp;
    }
    (*l)->head = temp;
    (*l)->sz++;
}
void push_back(list **l,struct TreeNode *n){
    if(*l == NULL){
        *l = (list*)malloc(sizeof(list));
        (*l)->sz = 0;
        (*l)->head = (*l)->tail = NULL;
    }
    node *temp = (node*)malloc(sizeof(node));
    temp->val = n;
    temp->next = NULL;
    temp->prev = (*l)->tail;
    if((*l)->tail){
        (*l)->tail->next = temp;
    }else{
        (*l)->head = temp;
    }
    (*l)->tail = temp;
    (*l)->sz ++;
}
void pop_front(list **l){
    if(*l == NULL||(*l)->head == NULL){
        return;
    }
    node *temp = (*l)->head;
    (*l)->head = temp->next;
    if((*l)->head){
        (*l)->head->prev = NULL;
    }else{
        (*l)->tail = NULL;
    }
    free(temp);
    (*l)->sz--;
    if((*l)->sz == 0){
        free(*l);
        *l = NULL;
    }
}
void pop_back(list **l){
    if(*l == NULL||(*l)->tail == NULL){
        return;
    }
    node *temp = (*l)->tail;
    (*l)->tail = temp->prev;
    if((*l)->tail){
        (*l)->tail->next = NULL;
    }else{
        (*l)->head = NULL;
    }
    free(temp);
    (*l)->sz--;
    if((*l)->sz == 0){
        free(*l);
        *l = NULL;
    }
}
struct TreeNode* front(list *l){
    if(!l||!l->head)return NULL;
    return l->head->val;
}
struct TreeNode* back(list *l){
    if(!l||!l->tail)return NULL;
    return l->tail->val;
}
int size(list *l){
    return l?l->sz:0;
}
int lvl=0;
void dfs(struct TreeNode *root,int l){
    if(!root)return;
    if(lvl<l)lvl = l;
    dfs(root->left,l+1);
    dfs(root->right,l+1);
}
void dfs1(struct TreeNode *root,int arr[],int index){
    if(!root)return;
    if(arr[index]==-200){
        arr[index]=root->val;
    }
    dfs1(root->right,arr,index+1);
    dfs1(root->left,arr,index+1);

}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if(!root){
        *returnSize = 0;
        return NULL;
    };
    lvl = 0;
    dfs(root,1);
    *returnSize = lvl;
    int *arr = (int*)malloc(lvl*sizeof(int));
    for(int i=0;i<lvl;i++)arr[i]=-200;
    dfs1(root,arr,0);
    return arr;
    /*
    list *l = NULL;
    push_back(&l,root);
    while(size(l)){
        struct TreeNode *v = front(l);
        pop_front(&l);
        printf("%d\n",v->val);
        if(v->right){
            push_back(&l,v->right);
        }
        if(v->left){
            push_back(&l,v->left);
        }
    }
    */
}
void bfs(struct TreeNode* root) {
    if(!root)return;
    list *l = NULL;
    push_back(&l,root);
    while(size(l)){
        struct TreeNode *v = front(l);
        pop_front(&l);
        printf("%d\n",v->val);
        if(v->right){
            push_back(&l,v->right);
        }
        if(v->left){
            push_back(&l,v->left);
        }
    }
}
int main(){

}


