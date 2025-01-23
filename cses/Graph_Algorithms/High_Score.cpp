
#include<bits/stdc++.h>
#define endl '\n'
const long long N=2510;
long long dist[N];
std::vector<long long>E1[N],E2[N];
std::vector<std::array<long long,3>>edges;
bool vis1[N],vis2[N];
void dfs(long long source){
    if(vis1[source])return;
    vis1[source]=true;
    for(long long x:E1[source]){
        dfs(x);
    }
}
void dfs1(long long source){
    if(vis2[source])return;
    vis2[source]=true;
    for(long long x:E2[source]){
        dfs1(x);
    }
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);std::cout.tie(NULL);
    dist[1]=0;
    for(long long i=2;i<N;i++)dist[i]=1e18;
    long long a,b,c,n,m;std::cin>>n>>m;
    for(long long i=0;i<m;i++){
        std::cin>>a>>b>>c;
        E1[a].push_back(b);
        E2[b].push_back(a);
        edges.push_back({a,b,-c});
    }
    dfs(1),dfs1(n);
    sort(edges.begin(),edges.end(),[](std::array<long long,3>a,std::array<long long,3>b){
            return a[2]<b[2];
            });
    for(long long i=1;i<=n;i++){
        for(std::array<long long,3>x:edges){
            if(dist[x[1]]>dist[x[0]]+x[2]){
                dist[x[1]]=dist[x[0]]+x[2];
                if(i==n && vis1[x[1]] && vis2[x[1]]){
                    std::cout<<-1<<endl;
                    return 0;
                }
            }
        }
    }
    std::cout<<-dist[n]<<endl;
}
