#include<stdio.h>
int main(void)
{
    char array[20];
    int k,g=0;
    scanf("%d",&k);
    if(k==1)
    {
        scanf("%s",array);
        if(array[0]=='H')
            printf("YES\nH");
        else if(array[0]=='.')
            printf("YES\nB");
    }
    else
    {
        scanf("%s",array);
        for(size_t i=0;i<k;i++)
        {
            if(array[i]=='H' && array[i+1]=='H')
            {
                printf("NO\n");
                g=0;
                break;
            }
            else if(array[i] == '.')
            {
                array[i] = 'B';
                g=1;
            }

        }
        if(g==1)
        {
            printf("YES\n");
            printf("%s",array);
        }
    }
}
