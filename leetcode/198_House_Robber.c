int max(int a,int b){
    return a>b?a:b;
}
int rob(int* nums, int numsSize) {
    for(int i=0;i<numsSize;i++){
        int M = 0;
        for(int j=0;j<i-1;j++){
            M = max(M,nums[j]);
        }
        nums[i]=nums[i]+M;
    }
    int ans = 0;
    for(int i=0;i<numsSize;i++){
        ans = max(ans,nums[i]);
    }
    return ans;
}
