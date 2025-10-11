#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TABLE_SIZE 200050
typedef struct Number{
    int val;
    struct Number *next;
}number;
int Hash(int x){
    unsigned int y= (unsigned int)x * 2654435761U;
    return y%TABLE_SIZE;
}
number* Hash_table[TABLE_SIZE];
bool Hash_table_insert(number *n){
    if(n==NULL)return false;
    int index = Hash(n->val);
    n->next = Hash_table[index];
    Hash_table[index]=n;
    return true;
}
number* Hash_table_lookup(number *n){
    int index = Hash(n->val);
    number *tmp = Hash_table[index];
    while(tmp != NULL && tmp->val!=n->val){
        tmp=tmp->next;
    }
    return tmp;
}
number *Hash_table_delete(number *n){
    int index = Hash(n->val);
    number *tmp = Hash_table[index];
    number *prev = NULL;
    while(tmp != NULL && tmp->val!=n->val){
        prev = tmp;
        tmp=tmp->next;
    }
    if(tmp == NULL)return NULL;
    if(prev == NULL){
        Hash_table[index]=tmp->next;
    }else{
        prev->next = tmp->next;
    }
    return tmp;
}
int cnt = 0;
number arr[TABLE_SIZE];

typedef struct {

} RandomizedSet;


RandomizedSet* randomizedSetCreate() {
    cnt = 0;
    for(int i=0;i<TABLE_SIZE;i++){
        Hash_table[i]=NULL;
    }
    return NULL;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    number a = {.val = val};
    if(Hash_table_lookup(&a) == NULL){
        arr[cnt].val = val;
        arr[cnt].next = NULL;
        if(Hash_table_insert(&arr[cnt])){
            cnt++;
            return true;
        }
    }
    return false;

}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    number tmp = {.val = val};
    number* deleted = Hash_table_delete(&tmp);
    if(deleted == NULL){
        return false;
    } else {
        int del_idx = deleted - arr;
        if(del_idx != cnt - 1) {
            arr[del_idx] = arr[cnt - 1];
            Hash_table_delete(&arr[cnt - 1]);
            Hash_table_insert(&arr[del_idx]);
        }
        cnt--;
        return true;
    }

}

int randomizedSetGetRandom(RandomizedSet* obj) {
    int index = rand()%cnt;
    return arr[index].val;
}

void randomizedSetFree(RandomizedSet* obj) {
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);

 * bool param_2 = randomizedSetRemove(obj, val);

 * int param_3 = randomizedSetGetRandom(obj);

 * randomizedSetFree(obj);
 */
