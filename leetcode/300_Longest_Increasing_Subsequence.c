int lengthOfLIS(int* nums, int numsSize) {
    int ans[numsSize];
    for(int i=0;i<numsSize;i++){
        ans[i]=1;
    }
    for(int i=0;i<numsSize;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                if(ans[i]<ans[j]+1){
                    ans[i]=ans[j]+1;
                }
            }
        }
    }
    int global_ans = 1;
    for(int i=0;i<numsSize;i++){
        if(global_ans<ans[i]){
            global_ans = ans[i];
        }
    }
    return global_ans;
}
