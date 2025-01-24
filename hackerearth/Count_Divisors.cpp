#include<stdio.h>
int main(void)
{
    int l,r,k,n=0;
    scanf("%d%d%d",&l,&r,&k);
    for(size_t i=l;i<=r;i++){
        if(i%k==0){
            n++;
        }
    }
    printf("%d",n);
}
