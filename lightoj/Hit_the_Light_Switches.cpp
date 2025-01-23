
#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int parent[N],sz[N];
int find(int source){
    if(parent[source]==source){
        return source;
    }else{
        return parent[source]=find(parent[source]);
    }
}
void add(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return;
    if(sz[a]<sz[b])swap(a,b);
    parent[b]=a;
    sz[a]+=sz[b];
}
vector<int>edges[N],revedges[N];
vector<int>edges1[N];
bool vis[N];
void dfs(int source,stack<int>&stk){
    if(vis[source])return;
    vis[source]=true;
    for(int x:revedges[source])dfs(x,stk);
    stk.push(source);
}
void orginaldfs(int source,vector<int>v){
    if(vis[source])return;
    vis[source]=true;
    for(int x:edges[source])orginaldfs(x,v);
    v.push_back(source);
}
void topdfs(int source,vector<int>&ans){
    if(vis[source])return;
    vis[source]=true;
    for(int u:edges1[source]){
        topdfs(u,ans);
    }
    ans.push_back(source);
}
void make(int n){
    for(int i=0;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
        edges[i].clear();
        revedges[i].clear();
        edges1[i].clear();
        vis[i]=false;
    }
}
void checkdfs(int source){
    if(vis[source])return;
    vis[source]=true;
    for(int x:edges1[source])checkdfs(x);
}
void sol(int test){
    int n,m;cin>>n>>m;
    make(n);
    pair<int,int> E[m];
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        E[i]={a,b};
        edges[a].push_back(b);
        revedges[b].push_back(a);
    }
    stack<int>stk;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,stk);
        }
    }
    for(int i=1;i<=n;i++){
        vis[i]=false;
    }
    while(!stk.empty()){
        vector<int>v;
        int k=stk.top();
        stk.pop();
        orginaldfs(k,v);
        for(size_t i=1;i<v.size();i++){
            add(v[i],v[i-1]);
        }
    }
    for(int i=0;i<m;i++){
        edges1[find(E[i].first)].push_back(find(E[i].second));
    }
    for(int i=1;i<=n;i++){
        vis[i]=false;
    }
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(!vis[find(i)]){
            topdfs(find(i),ans);
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<=n;i++){
        vis[i]=false;
    }
    int total=0;
    for(int x:ans){
        if(!vis[x]){
            total++;
            checkdfs(x);
        }
    }
    cout<<"Case "<<test<<": "<<total<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int test=1;
    int t;cin>>t;while(t--)sol(test++);
}

