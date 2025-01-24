#include<stdio.h>
int main(void)
{
	int n,s=1;
	scanf("%d",&n);
	for(size_t i=1;i<=n;i++){
		s=s*i;
	}
	printf("%d",s);
}
