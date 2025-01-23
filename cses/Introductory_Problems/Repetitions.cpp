#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int m=1;
	int k=1;
	int len=s.size();
	for(int i=0;i<len-1;i++)
	{
		if(s[i]==s[i+1])
		{
			m++;
			k=max(k,m);
		}
		else
		{
			m=1;
		}
	}
	cout<<k<<'\n';
	return 0;
}
