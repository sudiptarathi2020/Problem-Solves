#include <stdlib.h>
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *ret_arr = (int*)malloc(sizeof(int) * numsSize);
    int *prefix_mul = (int*)malloc(sizeof(int)*numsSize);
    int *suffix_mul = (int*)malloc(sizeof(int)*numsSize);
    for(int i = 0;i<numsSize;i++){
        prefix_mul[i] = nums[i];
        suffix_mul[numsSize-i-1]=nums[numsSize-i-1];
        if(i){
            prefix_mul[i] *= prefix_mul[i-1];
            suffix_mul[numsSize-i-1] *= suffix_mul[numsSize-i];
        }
    }
    for(int i = 0; i<numsSize;i++){
        ret_arr[i] = (i==0)?suffix_mul[i+1]:(i==numsSize-1)?prefix_mul[i-1]:prefix_mul[i-1]*suffix_mul[i+1];
    }
    *returnSize = numsSize;
    free(prefix_mul);
    free(suffix_mul);
    return ret_arr;
}
