
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=5e6+10;
int main()
{
	vector<int>phi(N+1);
	for(int i=0;i<=N;i++)
	{
		phi[i]=i;
	}
	for(int i=2;i<=N;i++)
	{
		if(phi[i]==i)
		{
			for(int j=i;j<=N;j+=i)
			{
				phi[j]-=phi[j]/i;
			}
		}
	}
	vector<ull>sum(N+1);
	sum[0]=0;
	for(int i=1;i<=N;i++)
	{
		sum[i]=(ull)phi[i]*(ull)phi[i]+sum[i-1];
	}
	int test_case;
	cin>>test_case;
	for(int test=1;test<=test_case;test++)
	{
		int a,b;
		cin>>a>>b;
		cout<<"Case "<<test<<": "<<sum[b]-sum[a-1]<<'\n';
	}
	return 0;
}
