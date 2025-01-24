#include<stdio.h>
int main()
{
    int n;
    unsigned const int mod=1000000007;
    unsigned long long int k=1;
    int array[1000];
    scanf("%d",&n);
    for(size_t i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    for(size_t j=0;j<n;j++){
        k = (k*array[j])%mod;
    }
    printf("%llu",k);
    return 0;
}
