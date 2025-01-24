
#include<bits/stdc++.h>
using namespace std;
const int N=10050;
list<int>edges[N];
int in[N],low[N],vis[N],hoise[N],timer,ans;
void dfs(int v,int p=-1){
    vis[v]=1;
    in[v]=low[v]=timer++;
    int child=0;
    for(int to:edges[v]){
        if(to==p)continue;
        if(vis[to]){
            low[v]=min(low[v],in[to]);
        }else{
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>=in[v] and p!=-1){
                hoise[v]++;
                if(hoise[v]==1)ans++;
            }
            child++;
        }
    }
    if(p==-1 and child>1){
        hoise[v]++;
        if(hoise[v]==1)ans++;
    }
}
void sol(int test){
    timer=ans=0;
    int a,b,n,m;cin>>n>>m;
    for(int i=0;i<=n;i++){
        edges[i].clear();
        in[i]=low[i]=hoise[i]=vis[i]=0;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1);
    cout<<"Case "<<test<<": "<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int test;cin>>test;
    for(int i=1;i<=test;i++){
        sol(i);
    }
}
