#include<stdio.h>
int main(void)
{
    int i,k=0,j,price1,price2,n1=0,n2=0,s=0;
    int array[10][2];
    scanf("%d",&i);
    for(;k<i;k++)
    {
        s=0,n1=0,n2=0;
        scanf("%d%d",&price1,&price2);
        scanf("%d",&j);
        if(j>0 && j<11)
        {
            for(size_t n=0;n<j;n++)
            {
                for(size_t m=0;m<2;m++)
                {
                    scanf("%d",&array[n][m]);
                }
            }

        }
        for(size_t h=0;h<j;h++)
        {
            n1+=array[h][0];
        }
        for(size_t h=0;h<j;h++)
        {
            n2+=array[h][1];
        }
        if((price1>price2 && n1>n2) || (price1<price2 && n1<n2))
        {
            s=price1*n2+price2*n1;
        }
        else
        {
            s=price1*n1+price2*n2;
        }
        printf("%d\n",s);
    }
}
