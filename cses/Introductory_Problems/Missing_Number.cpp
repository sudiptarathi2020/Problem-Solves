#include<stdio.h>
int main()
{
	long long n,ans;
	scanf("%lld",&n);
	ans=(n*(n+1))/2;
	for(long long i=1;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		ans-=a;
	}
	printf("%lld\n",ans);
	return 0;
}
