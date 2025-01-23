
#include<bits/stdc++.h>
using namespace std;
const int mx=2e4+10;
vector<int>v[mx];
bool vis[mx];
bool check[mx];
long long bfs(int n){
	
	//memset(check,false,sizeof(mx));
	long long vam=1,lyk=0;
	vis[n]=true;
	queue<int>q;
	q.push(n);
	while(!q.empty())
	{
		int u=q.front();
		//vis[u]=true;
		q.pop();
		for(int i=0;i<(int)v[u].size();i++)
		{
			if(vis[v[u][i]]){
				continue;
			}
            vis[v[u][i]]=true;
			q.push(v[u][i]);
			if(check[u]==false)
			{
				check[v[u][i]]=true;
				lyk++;
			}
			if(check[u]==true)
			{
				check[v[u][i]]=false;
				vam++;
			}
		}
	}
	return max(vam,lyk);
}
int main()
{
    int test_case;
    scanf("%d",&test_case);
    for(int test=1;test<=test_case;test++)
    {
        for(int i=0;i<mx;i++){
            v[i].clear();
            vis[i]=false;
            check[i]=false;
        }
        int a,b,n;
        scanf("%d",&n);
        vector<int>q;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            q.push_back(a);
            q.push_back(b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        long long ans=0;
		for(int i=0;i<(int)q.size();i++)
		{
			if(!vis[q[i]] and !v[q[i]].empty()){
				ans+=bfs(q[i]);
			}
		}
		printf("Case %d: %lld\n",test,ans);
    }
    return 0;
}
