#include<stdio.h>
#include<string.h>
int main()
{
    int len,k=0;
    char array[20];
    fgets(array,20,stdin);
    len=strlen(array)-1;
    if(len%3==0){
        for(size_t i=0;i<len/3;i++){
            if(array[i]!='z'){
                printf("No\n");
                k=0;
                break;
            }
            else
                k=1;
        }

    }
    else
        printf("No\n");
    if(k==1){
        if(array[len/3]=='z'){
            printf("No\n");
        }
        else
            printf("Yes\n");
    }
}
