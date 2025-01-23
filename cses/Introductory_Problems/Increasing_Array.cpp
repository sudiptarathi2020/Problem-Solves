#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long arr[n];
	long long brr[n];
	long long m=0;
	cin>>arr[0];
	brr[0]=arr[0];
	for(long long i=1;i<n;i++)
	{
		cin>>arr[i];
		brr[i]=arr[i];
		if(arr[i]<arr[i-1])
		{
			arr[i]+=(arr[i-1]-arr[i]);
		}
		m+=(arr[i]-brr[i]);
	}
	cout<<m<<'\n';
	return 0;
}
