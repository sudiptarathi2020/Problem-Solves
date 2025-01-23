
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
const int N=200010,lg=19;
vector<int>edges[N],father[N];
int st[N],en[N],timer=0;
void dfs(int source,int parent){
    st[source]=timer++;
    father[source][0]=parent;
    for(int i=1;i<lg;i++){
        father[source][i]=father[father[source][i-1]][i-1];
    }
    for(int x:edges[source]){
        if(x^parent){
            dfs(x,source);
        }
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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a,b,n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        father[i].resize(lg);
    }
    for(int i=2;i<=n;i++){
        cin>>a;
        edges[a].push_back(i);
    }
    dfs(1,1);
    while(q--){
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
    return 0;
}
 
