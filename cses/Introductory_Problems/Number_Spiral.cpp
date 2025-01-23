#include<bits/stdc++.h>
#define ull unsigned long long 
using namespace std;
void solve()
{
	ull a,b;
	cin>>a>>b;
	a--;
	b--;
	if(a>=b)
	{
		if(a&1)
		{
			cout<<(a+1)*(a+1)-b<<'\n';
			return;
		}
		else
		{
			cout<<a*a+1+b<<'\n';
			return;
		}
	}
	else
	{
		if(b&1)
		{
			cout<<b*b+1+a<<'\n';
			return;
		}
		else
		{
			cout<<(b+1)*(b+1)-a<<'\n';
			return;
		}
	}
	return;
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int test;
	cin>>test;
	while(test--)
	{
		solve();
	}
	return 0;
}
