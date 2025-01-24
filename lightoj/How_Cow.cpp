#include<stdio.h>
int main()
{
    int t_c,a,b,c,d,n,posx,posy;
    scanf("%d",&t_c);
    int i=1,j;
    for(;i<=t_c;i++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        scanf("%d",&n);
        printf("Case %d:\n",i);
        for(j=0;j<n;j++)
        {
        scanf("%d%d",&posx,&posy);
        
        if(posx>=a && posx<=c && posy>=b && posy<=d)
        {
            printf("Yes\n");
        }
        else 
        {
            printf("No\n");
        }
        }
    }
    return 0;
}
