
#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=50010;
int father[N],sz[N];
int root(int a){
    if(father[a]==a)return a;
    return father[a]=root(father[a]);
}
bool same(int a,int b){
    return root(a)==root(b);
}
void merge(int a,int b){
    a=root(a),b=root(b);
    if(a==b)return;
    if(sz[a]<sz[b])swap(a,b);
    father[b]=a;
    sz[a]+=sz[b];
}
const int lg=18;
int timer;
vector<pii>edges[N];
vector<pii>parent[N];
int start[N],finish[N];
void dfs(int source,int P,int val=0){
    start[source]=timer++;
    parent[source][0]={P,val};
    for(int i=1;i<lg;i++){
        parent[source][i].first=parent[parent[source][i-1].first][i-1].first;
        parent[source][i].second=max(parent[source][i-1].second,parent[parent[source][i-1].first][i-1].second);
    }
    for(auto x:edges[source]){
        if(x.first==P)continue;
        dfs(x.first,source,x.second);
    }
    finish[source]=timer++;
}
bool is_an(int a,int b){
    return start[a]<=start[b] and finish[a]>=finish[b];
}
int lca(int a,int b){
    if(is_an(a,b))return a;
    if(is_an(b,a))return b;
    for(int i=lg-1;i>=0;i--){
        if(!is_an(parent[a][i].first,b)){
            a=parent[a][i].first;
        }
    }
    return parent[a][0].first;
}
int get_ans(int a,int b){
    int c=lca(a,b);
    int ans=0;
    for(int i=lg-1;i>=0;i--){
        if(is_an(c,parent[a][i].first)){
            ans=max(ans,parent[a][i].second);
            a=parent[a][i].first;
        }
    }
    for(int i=lg-1;i>=0;i--){
        if(is_an(c,parent[b][i].first)){
            ans=max(ans,parent[b][i].second);
            b=parent[b][i].first;
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    for(int tt=1;tt<=t;tt++){
        timer=0;
        memset(father,0,sizeof(father));
        memset(start,0,sizeof(start));
        memset(finish,0,sizeof(finish));
        memset(sz,1,sizeof(sz));
        for(vector<pii>&x:edges)x.clear();
        for(vector<pii>&x:parent){
			x.clear();
            x.resize(lg+1);
		}
        iota(father,father+N,0);
        int n,m;cin>>n>>m;
        vector<pair<int,pii>>X(m);
        for(int i=0;i<m;i++){
            cin>>X[i].second.first>>X[i].second.second>>X[i].first;
        }
        sort(X.begin(),X.end());
        for(pair<int,pii>x:X){
            if(same(x.second.first,x.second.second))continue;
            merge(x.second.first,x.second.second);
            edges[x.second.first].push_back({x.second.second,x.first});
            edges[x.second.second].push_back({x.second.first,x.first});
        }
        dfs(1,1);
        int q;cin>>q;
        cout<<"Case "<<tt<<": \n";
        while(q--){
            int a,b;cin>>a>>b;
            cout<<get_ans(a,b)<<endl;
        }
    }
}

