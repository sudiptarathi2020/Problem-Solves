#include<bits/stdc++.h>
using namespace std;
const int N = 100050;
vector<int>edges[N];
int initial[N];
bool vis[N];
void dfs(int source,int parent){
    vis[source]=true;
    initial[source]=initial[parent]^1;
    for(int x:edges[source]){
        if(vis[x]==false){
            dfs(x,source);
        }
    }
}
int main(){
    int x,y,n,m;cin>>n>>m;
    pair<int,int> ed[m];
    for(int i=0;i<m;i++){
        cin>>x>>y;
        ed[i]={x,y};
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            dfs(i,i);
        }
    }
    for(int i=0;i<m;i++){
        if(initial[ed[i].first]==initial[ed[i].second]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<initial[i]+1<<" ";
    }
}
