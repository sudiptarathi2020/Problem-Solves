
#include<bits/stdc++.h>
using namespace std;
const int n=400;
int parent[n];
int Size[n];
void make(int a)
{
	parent[a]=a;
	Size[a]=1;
}
int find(int a)
{
	if(a==parent[a])
	{
		return a;
	}
	return parent[a]=find(parent[a]);
}
void Union(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a!=b)
	{
		if(Size[a]<Size[b])
		{
			swap(a,b);
		}
		parent[b]=parent[a];
		Size[a]+=Size[b];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test;
	cin>>test;
	for(int bt=1;bt<=test;bt++)
	{
		memset(parent,0,sizeof(parent));
		int a,b;
		cin>>a>>b;
		map<pair<int,int>,int>mp;
		int k=0;
		for(int i=0;i<b;i++)
		{
			for(int j=0;j<a;j++)
			{
				mp[{i,j}]=k;
				make(k);
				k++;
			}
		}
		string s[b];
		int c,d;
		for(int i=0;i<b;i++)
		{
			cin>>s[i];
			for(int k=0;k<a;k++)
			{
				if(s[i][k]=='@')
				{
					c=i;
					d=k;
					s[i][k]='.';
				}
			}
		}
		for(int i=0;i<b-1;i++)
		{
			for(int j=0;j<a-1;j++)
			{
				if(s[i][j]==s[i+1][j] and s[i][j]=='.')
				{
					Union(mp[{i,j}],mp[{i+1,j}]);
				}
				if(s[i][j]==s[i][j+1] and s[i][j]=='.')
				{
					Union(mp[{i,j}],mp[{i,j+1}]);
				}
			}
		}
		for(int j=0;j<a-1;j++)
		{
			if(s[b-1][j]==s[b-1][j+1] and s[b-1][j]=='.')
			{
				Union(mp[{b-1,j}],mp[{b-1,j+1}]);
			}
		}
		for(int j=0;j<b-1;j++)
		{
			if(s[j][a-1]==s[j+1][a-1] and s[j][a-1]=='.')
			{
				Union(mp[{j,a-1}],mp[{j+1,a-1}]);
			}
		}
		cout<<"Case "<<bt<<": "<<Size[find(mp[{c,d}])]<<'\n';
	}
	return 0;
}
