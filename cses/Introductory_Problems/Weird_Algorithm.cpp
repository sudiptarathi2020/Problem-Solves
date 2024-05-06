#include<stdio.h>
int main()
{
	long long n;
	scanf("%lld",&n);
	printf("%lld ",n);
	while(n!=1)
	{
		if(n&1)
		{
			n*=3;
			n++;
		}
		else
		{
			n/=2;
		}
		printf("%lld ",n);
	}
	printf("\n");
	return 0;
}
