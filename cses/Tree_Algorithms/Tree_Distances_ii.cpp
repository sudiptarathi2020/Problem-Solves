#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=200050;
list<ll>edges[N];
ll sub[N],ans[N],Ans=0;
void szdfs(ll source,ll P=0){
    sub[source]=1;
    for(ll to:edges[source]){
        if(to!=P){
            szdfs(to,source);
            sub[source]+=sub[to];
        }
    }
}
void ansdfs(ll source,ll p=0,ll depth=0){
    Ans+=depth;
    for(ll to:edges[source]){
        if(to!=p){
            ansdfs(to,source,depth+1);
        }
    }
}
void dfs(ll source,ll p=0){
    for(ll to:edges[source]){
        if(to!=p){
            ans[to]=ans[source]-2*sub[to]+sub[1];
            dfs(to,source);
        }
    }
}
int main(){
    ll a,b,n;cin>>n;
    for(ll i=1;i<n;i++){
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    szdfs(1);
    ansdfs(1);
    ans[1]=Ans;
    dfs(1);
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}
