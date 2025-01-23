#include<bits/stdc++.h>
#include <climits>
#define ll long long
typedef std::pair<ll,ll> pll;
using namespace std;
const ll inf=LLONG_MAX;
int main(){
    ll a,b,c,n,m;cin>>n>>m;
    vector<pll>edges[n+1];
    for(ll i=0;i<m;i++){
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
    }
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    vector<ll>dist(n+1,inf);
    vector<bool>vis(n+1,false);
    dist[1]=0;
    pq.push({0,1});
    while(pq.size()){
        pll x=pq.top();
        pq.pop();
        if(vis[x.second])continue;
        vis[x.second]=true;
        for(pll y:edges[x.second]){
            if(x.first+y.second<dist[y.first]){
                dist[y.first]=x.first+y.second;
                pq.push({dist[y.first],y.first});
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";
}
