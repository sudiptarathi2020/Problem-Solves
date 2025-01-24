#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	//freopen("vjd.txt","r",stdin);
	ll test;
	cin>>test;
	while(test--)
	{
		ll a,b,k=0,max0=0,m=0,k1=0,max1=0,m1=0;
		cin>>a>>b;
		string aa[a];
		//ll aaa[a];
		for(ll i=0;i<a;i++)
		{
			cin>>aa[i];
		}
		for(ll i=0;i<a;i++)
		{
			k=0;
			for(ll j=0;j<b-1;j++)
			{
				if(aa[i][j]==aa[i][j+1]&&aa[i][j]=='#')
				{
					k++;
					if(k>max0)
					{
						max0=k;
					}
				}
				else
				{
					k=0;
				}
			}
			if(max0>m)
			{
				m=max0;
			}
		}
		for(ll i=0;i<b;i++)
		{
			k1=0;
			for(ll j=0;j<a-1;j++)
			{
				if(aa[j][i]==aa[j+1][i]&&aa[j][i]=='#')
				{
					k1++;
					if(k1>max1)
					{
						max1=k1;
					}
				}
				else
				{
					k1=0;
				}
			}
			if(max1>m1)
			{
				m1=max1;
			}
		}
		ll p=max(m,m1);
		cout<<p+1<<'\n';		
	}
	return 0;
}
