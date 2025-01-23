
#include<stdio.h>
#include<math.h>
int main()
{
    long long int mid,max,min,s,minn,maxx;
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld",&s);
        min=sqrt(s);
        if(s==min*min)
            min=min-1;
        minn=min*min+1;
        max=min+1;
        maxx=max*max;
        mid=(minn+maxx)/2;
        if(s==mid)
            printf("Case %d: %lld %lld\n",i,max,max);
        else if(s>mid)
        {
            if(minn%2)
            {
                printf("Case %d: %lld %lld\n",i,max-(s-mid),max);
            }
            else
                printf("Case %d: %lld %lld\n",i,max,max-(s-mid));
        }
        else
        {
            if(minn%2)
            {
                printf("Case %d: %lld %lld\n",i,max,max-(mid-s));
            }
            else
                printf("Case %d: %lld %lld\n",i,max-(mid-s),max);
        }

    }
    return 0;  
}
