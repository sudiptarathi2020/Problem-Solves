
#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const ll N=5010;
const ll inf=1<<30;
ll vis[N];
using pii=pair<ll,ll>;
vector<pii>edges[N];
int main(){
    ll t;cin>>t;
    for(ll tt=1;tt<=t;tt++){
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<=n;i++){
            edges[i].clear();
            vis[i]=0;
        }
        for(ll i=0;i<m;i++){
            ll a,b,c;cin>>a>>b>>c;
            edges[a].push_back({b,c});
            edges[b].push_back({a,c});
        }
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,1});
        vector<ll>A;
        if(n==1)A.push_back(0);
        while(pq.size()){
            pii x=pq.top();
            pq.pop();
            vis[x.second]++;
            if(vis[x.second]>3)continue;
            for(auto y:edges[x.second]){
                if(vis[y.first]<3){
                    pq.push({y.second+x.first,y.first});
                }
                if(y.first==n){
                    A.push_back(y.second+x.first);
                }
            }
        }
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(),A.end()),A.end());
        cout<<"Case "<<tt<<": "<<A[1]<<endl;
    }
}
