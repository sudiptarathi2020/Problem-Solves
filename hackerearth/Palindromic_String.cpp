#include<stdio.h>
#include<string.h>
int main(void)
{
    int l,h=0,k=0;
    char string[1000];
    fgets(string,1000,stdin);
    l=strlen(string)-2;
    while(l>h){
        if(string[l]!=string[h])
        {printf("NO");
            k=0;
            break;}
        k=1;
        l--;
        h++;
    }
    if(k==1)
        printf("YES");
}
