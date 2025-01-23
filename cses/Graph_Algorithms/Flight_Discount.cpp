#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=100001;
list<pair<ll,ll>>edges[N];
array<ll,2> dist[N];
struct state{
    ll x,used;ll cost;
    state(ll _x,ll _used,ll _cost){
        x=_x,used=_used,cost=_cost;
    }
    bool operator<(const state& other)const{
        return other.cost<cost;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll x,y,z,n,m;cin>>n>>m;
    for(ll i=0;i<m;i++){
        cin>>x>>y>>z;
        edges[x].push_back({y,z});
    }
    for(ll i=0;i<=n;i++){
        dist[i]={1ll<<60,1ll<<60};
    }
    priority_queue<state>pq;
    pq.push(state(1,0,0));dist[1]={0,0};
    while(pq.size()){
        state current=pq.top();
        pq.pop();
        ll current_cost=dist[current.x][current.used];
        if(current.cost!=current_cost)continue;
        if(current.x==n)break;
        for(pair<ll,ll>X:edges[current.x]){
            if(!current.used){
                if(dist[X.first][1]>current_cost+(X.second>>1)){
                    dist[X.first][1]=current_cost+(X.second>>1);
                    pq.push(state(X.first,1,dist[X.first][1]));
                }
            }
            if(dist[X.first][current.used]>current_cost+X.second){
                dist[X.first][current.used]=current_cost+X.second;
                pq.push(state(X.first,current.used,dist[X.first][current.used]));
            }
        }
    }
    cout<<dist[n][1]<<endl;
}
