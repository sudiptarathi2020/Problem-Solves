#include<stdio.h>
int main()
{
    int tc;
    long long int n,k;
    scanf("%d",&tc);
    int i=1;
    long long int j=2;
    for(;i<=tc;i++)
    {
        j=2;
        scanf("%lld",&n);
        if(n%2==1)
        {
            printf("Case %d: Impossible\n",i);
        }
        else
        for(;j<=(n/2);j+=2)
        {
            if(n%j==0 && (n/j)%2==1)
            {
                printf("Case %d: %lld %lld\n",i,(n/j),j);
                break;
            }
            else if(j==(n/2))
            {
                printf("Case %d: Impossible\n",i);
            }
        }
        
    }
    return 0;
}
