#include<stdio.h>
#include<algorithm>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int arr[b];
		for(int i=0;i<b;i++)scanf("%d",&arr[i]);
		std::sort(arr,arr+b);
		int i;
		int k=0;
		for(i=0;i<b;i++)
		{
			if(arr[i]<=a)
			{
				a-=arr[i];
				k++;
			}
			else
			{
				break;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}
