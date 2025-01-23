
#include<bits/stdc++.h>
using pii=std::pair<int,int>;
using namespace std;
const int N=200050,lg=18;
vector<int>edges[N],father[N];
int st[N],en[N],timer=0;
int cnt[N];
void dfs(int source,int parent){
    st[source]=timer++;
    father[source][0]=parent;
    for(int i=1;i<lg;i++){
        father[source][i]=father[father[source][i-1]][i-1];
    }
    for(int x:edges[source]){
        if(x^parent)dfs(x,source);
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
        if(!is_an(father[a][i],b)){
            a=father[a][i];
        }
    }
    return father[a][0];
}
void Dfs(int source){
    for(int x:edges[source]){
        if(x^father[source][0]){
            Dfs(x);
            cnt[source]+=cnt[x];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin>>n;
    int m;cin>>m;
    for(int i=0;i<=n;i++){
        father[i].resize(lg);
    }
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1,1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        int c=lca(a,b);
        cnt[a]++,cnt[b]++;
        cnt[c]--;
        if(c!=1){
            cnt[father[c][0]]--;
        }
    }
    Dfs(1);
    for(int i=1;i<=n;i++){
        cout<<cnt[i]<<"\n";
    }
}
