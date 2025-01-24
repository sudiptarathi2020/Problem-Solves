#include<iostream>
using namespace std;
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int k=a/c;
		if(a%c)k++;
		int p=b/c;
		if(b%c)p++;
		cout<<k+p<<'\n';
	}
	return 0;
}
