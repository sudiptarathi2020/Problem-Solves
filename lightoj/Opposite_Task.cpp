#include<stdio.h>
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n<=10)
        printf("%d 0\n",n);
        else
        printf("%d %d\n",10,n-10);
    }
    return 0;
}
