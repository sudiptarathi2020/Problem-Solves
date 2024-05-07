//https://codeforces.com/problemset/problem/990/D
#include<stdio.h>
int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(a==1 || b==1){
        if(a==1 && b==1){
            if(n==2 || n==3){
                printf("NO\n");
            }else{
                if(n==1){
                    printf("YES\n");
                    printf("0");
                }else{
                    printf("YES\n");
                    for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                            if(i+1==j || j+1==i){
                                printf("1");
                            }else{
                                printf("0");
                            }
                        }
                        printf("\n");
                    }
                }
            }
        }else{
            if(a==1){
                printf("YES\n");
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(i==j){
                            printf("0");
                            continue;
                        }
                        if(i<b-1|| j<b-1){
                            printf("1");
                        }else{
                            printf("0");
                        }
                    }
                    printf("\n");
                }
            }else{
                printf("YES\n");
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(i<a-1 || j<a-1){
                            printf("0");
                        }else{
                            if(i==j){
                                printf("0");
                            }else{
                                printf("1");
                            }
                        }
                    }
                    printf("\n");
                }
            }
        }
    }else{
        printf("NO\n");
    }
    return 0;
}
