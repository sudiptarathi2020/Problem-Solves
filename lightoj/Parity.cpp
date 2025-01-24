
#include<iostream>
using namespace std;
int main()
{
	
	int n,k,count=0,t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		count=0;
		cin>>n;
	for(;n>0;n/=2)
	{
		k=n%2;
		if(k==1)
		count++;
	}
	if(count%2==1)
	cout<<"Case "<<i<<": odd\n";
	else
	cout<<"Case "<<i<<": even\n";
	}
	return 0;
}
