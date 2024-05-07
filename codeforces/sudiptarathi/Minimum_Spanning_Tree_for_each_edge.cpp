//https://codeforces.com/problemset/problem/609/E
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int lg=20;
using pii=pair<int,int>;
vector<pii>edges[N];
pii father[N][lg];
int parent[N],sz[N];
int st[N],en[N];
int root(int a){
    if(parent[a]==a)return a;
    return parent[a]=root(parent[a]);
}
bool same(int a,int b){
    return root(a)==root(b);
}
void merge(int a,int b){
    a=root(a),b=root(b);
    if(a==b)return;
    if(sz[a]<sz[b])swap(a,b);
    parent[b]=a;
    sz[a]+=sz[b];
}
int timer=0;
void dfs(int source,int P,int val=0){
    st[source]=timer++;
    father[source][0]={P,val};
    for(int i=1;i<lg;i++){
        father[source][i].first=father[father[source][i-1].first][i-1].first;
        father[source][i].second=max(father[source][i-1].second,father[father[source][i-1].first][i-1].second);
    }
    for(pii x:edges[source]){
        if(x.first==P)continue;
        dfs(x.first,source,x.second);
    }
    en[source]=timer++;
}
bool is_an(int a,int b){
    return st[a]<=st[b] and en[a]>=en[b];
}
int lca(int a,int b){
    if(is_an(a,b))return a;
    if(is_an(b,a))return b;
    for(int i=lg-1;i>=0;i--){
        if(!is_an(father[a][i].first,b)){
            a=father[a][i].first;
        }
    }
    return father[a][0].first;
}
int get_ans(int a,int b){
    int c=lca(a,b);
    int ans=0;
    for(int i=lg-1;i>=0;i--){
        if(is_an(c,father[a][i].first)){
            ans=max(ans,father[a][i].second);
            a=father[a][i].first;
        }
    }
    for(int i=lg-1;i>=0;i--){
        if(is_an(c,father[b][i].first)){
            ans=max(ans,father[b][i].second);
            b=father[b][i].first;
        }
    }
    return ans;
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
    vector<array<int,5>>E(m);
    vector<pii>A;
    vector<long long>G(m);
    int cnt=0;
    for(auto &x:E){
        cin>>x[1]>>x[2]>>x[0];
        x[3]=0;
        x[4]=cnt;
        cnt++;
        A.push_back({x[1],x[2]});
    }
    sort(E.begin(),E.end());
    bool vis[m+1];
    memset(vis,false,sizeof(vis));
    long long ans=0;
    for(int i=0;i<m;i++){
        array<int,5>x=E[i];
        if(same(x[1],x[2]))continue;
        merge(x[1],x[2]);
        E[i][3]=true;
        edges[x[1]].push_back({x[2],x[0]});
        edges[x[2]].push_back({x[1],x[0]});
        ans+=(long long)x[0];
    }
    map<pair<int,int>,long long>mp;
    dfs(1,1);
    for(int i=0;i<m;i++){
        if(E[i][3]){
            G[E[i][4]]=ans;
        }else{
            int k=get_ans(E[i][1],E[i][2]);
            G[E[i][4]]=ans+(long long)E[i][0]-(long long)k;
        }
    }
    for(auto x:G){
        cout<<x<<endl;
    }
}
