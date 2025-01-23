#include<bits/stdc++.h>
using namespace std;
const int N=100050;
vector<int>edges[N],parent(N),vis(N);
int main(){
    int n,m,a,b;cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    queue<int>q;
    bool I=false;
    q.push(1);
    vis[1]=true;
    parent[1]=0;
    while(q.size()){
        int x=q.front();
        if(x==n)I=true;
        q.pop();
        for(int y:edges[x]){
            if(vis[y])continue;
            vis[y]=true;
            parent[y]=x;
            q.push(y);
        }
    }
    if(!I){
        cout<<"IMPOSSIBLE\n";
    }else{
        vector<int>rasta;
        while(n!=0){
            rasta.push_back(n);
            n=parent[n];
        }
        reverse(rasta.begin(),rasta.end());
        cout<<rasta.size()<<endl;
        for(int u:rasta){
            cout<<u<<" ";
        }
    }
}
