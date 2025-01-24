
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int M=501;
const int N=501;
char s[N][M];
int arr[N][M];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
static int cnt=0;
void dfs(int n,int m,int x,int y,int cc)
{
	
	if(arr[x][y]==2)
	{
		cnt++;
	}
	arr[x][y]=cc;
	for(int i=0;i<4;i++)
	{
		int dd=dx[i]+x;
		int yy=dy[i]+y;
		if(dd>=0 and dd<n and yy>=0 and yy<m)
		{
			if(arr[dd][yy]==1 or arr[dd][yy]==2)
			{
				dfs(n,m,dd,yy,cc);
			}
		}
	}
	return;
}
void solve(int c)
{
	int n,m,q;
	cin>>n>>m>>q;
	//char k[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>s[i][j];
			if(s[i][j]=='.')
			{
				arr[i][j]=1;
			}
			else if(s[i][j]=='C')
			{
				arr[i][j]=2;
			}
			else
			{
				arr[i][j]=0;
			}
		}
	}
	vector<int>ans;
	int cc=3;
	map<int,int>mmm;
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		cnt=0;
		if(arr[a][b]!=1)
		{
			ans.pb(mmm[arr[a][b]]);
		}
		else
		{
			dfs(n,m,a,b,cc);
			mmm[cc]=cnt;
			ans.pb(cnt);
		}
		cc++;
	}
	cout<<"Case "<<c<<":\n";
	for(int i=0;i<(int)ans.size();i++)
	{
		cout<<ans[i]<<'\n';
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test;
	cin>>test;
	int c=1;
	while(test--)
	{
		solve(c);
		c++;
	}
	return 0;
}
