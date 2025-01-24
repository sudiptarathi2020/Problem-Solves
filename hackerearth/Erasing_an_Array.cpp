#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n;
		scanf("%d",&n);
		int arr[n];
		int ans=1;
		for(int i=0;i<n;i++)scanf("%d",&arr[i]);
		for(int i=0;i<n-1;i++)
		{
			if(arr[i]==1 and arr[i+1]==0)
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
