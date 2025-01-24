#include<stdio.h>
int main(void)
{
    int l,h,w,n;
    scanf("%d%d",&l,&n);
    for(size_t i=0;i<n;i++){
        scanf("%d",&h);
        scanf("%d",&w);
        if(h<l || w<l){
            printf("UPLOAD ANOTHER\n");
        }
        else if(h==w && h>=l){
            printf("ACCEPTED\n");
        }
        else
            printf("CROP IT\n");
    }
}
