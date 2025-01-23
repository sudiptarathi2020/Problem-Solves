
#include<bits/stdc++.h>
#include <queue>
using namespace std;
void sol(int test){
    int n,m;cin>>n>>m;
    vector<pair<int,int>>edges[n+1];
    int dist[n+1];
    for(int i=1;i<=n;i++){
        dist[i]=1e9;
    }
    for(int i=0;i<m;i++){
        int x,y,z;cin>>x>>y>>z;
        edges[x].push_back({y,z});
        edges[y].push_back({x,z});
    }
    using pii=pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,1});dist[1]=0;
    while(pq.size()){
        pair<int,int>x=pq.top();
        pq.pop();
        for(pair<int,int>y:edges[x.second]){
            if(dist[y.first]>x.first+y.second){
                dist[y.first]=x.first+y.second;
                pq.push({dist[y.first],y.first});
            }
        }
    }
    cout<<"Case "<<test<<": ";
    if(dist[n]==1e9){
        cout<<"Impossible\n";
    }else{
        cout<<dist[n]<<endl;
    }
}
int main(){
    int test=1;
    int t;cin>>t;while(t--)sol(test++);
}
