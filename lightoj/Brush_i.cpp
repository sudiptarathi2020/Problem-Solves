
#include<stdio.h>
#include<string.h>
#define size 1000
int main()
{
    int arrsize,i,t,j,sum=0;
    int array[size];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        sum=0;
        scanf("%d",&arrsize);
        for(j=0;j<arrsize;j++)
        {
            scanf("%d",&array[j]);
            if(array[j]<0)array[j]=0;
        }
        for(j=0;j<arrsize;j++)
        {
            sum=sum+array[j];
        }
        printf("Case %d: %d\n",i,sum);
        memset(array,0,sizeof(array));
    }
    return 0;
}
