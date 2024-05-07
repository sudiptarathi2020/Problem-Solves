//https://codeforces.com/problemset/problem/20/C
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=LLONG_MAX;
struct djkastra{
    vector<vector<pair<ll,ll>>>v;
    vector<ll>parent;
    vector<ll>dist;
    vector<bool>vis;
    ll n;
    djkastra(){}
    djkastra(ll _n){
        this->n=_n;
        v.resize(n);
        parent.resize(n);
    }
    void add(ll a,ll b,ll c){
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    void dj(ll source){
        parent[source]=-1;
        dist.resize(n,inf);
        vis.resize(n,false);
    	multiset<pair<ll,ll>>st;
    	st.insert({0,source});
    	dist[source]=0;
    	while(!st.empty()){
    		pair<ll,ll> x=*st.begin();
    		st.erase(st.begin());
    		ll u=x.second;
    		if(vis[u]){
    			continue;
    		}
    		vis[u]=true;
    		for(pair<ll,ll> y:v[u]){
    			ll uu=y.first;
    			ll wwt=y.second;
    			if(wwt+dist[u]<dist[uu]){
    				dist[uu]=wwt+dist[u];
                    parent[uu]=u;
    				st.insert({dist[uu],uu});
    			}
    		}
            
       	}
    }
};
void sol(){
    ll n;cin>>n;
    ll m;cin>>m;
    djkastra D(n);
    for(ll i=0;i<m;i++){
        ll a,b,c;cin>>a>>b>>c;
        a--,b--;
        D.add(a,b,c);
    }
    D.dj(0);
    if(D.dist[n-1]==inf){
        cout<<"-1\n";
        return;
    }else{
        vector<ll>ans;
        ll prev=n-1;
        while(prev!=-1){
            ans.push_back(prev);
            prev=D.parent[prev];
        }
        reverse(ans.begin(),ans.end());
        for(ll i:ans){
            cout<<i+1<<" ";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;while(t--)sol();
}
