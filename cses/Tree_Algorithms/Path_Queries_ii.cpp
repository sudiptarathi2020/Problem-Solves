#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct seg{
    ll N;
    vector<ll>tree;
    seg(){}
    seg(ll _N){
        N=_N;
        tree.resize(N<<2);
    }
    void upd(ll node,ll start,ll end,ll pos,ll val){
        if(start==end){
            tree[node]=val;
            return;
        }
        ll mid=(start+end)>>1;
        if(pos<=mid){
            upd(node<<1,start,mid,pos,val);
        }else{
            upd(node<<1|1,mid+1,end,pos,val);
        }
        tree[node]=max(tree[node<<1],tree[node<<1|1]);
    }
    void upd(ll ind,ll val){
        upd(1,0,N-1,ind,val);
    }
    ll Q(ll node,ll start,ll end,ll left,ll right){
        if(start==left and end==right){
            return tree[node];
        }
        ll mid=(start+end)>>1;
        if(right<=mid){
            return Q(node<<1,start,mid,left,right);
        }else if(left>mid){
            return Q(node<<1|1,mid+1,end,left,right);
        }else{
            ll A=Q(node<<1,start,mid,left,mid);
            ll B=Q(node<<1|1,mid+1,end,mid+1,right);
            return max(A,B);
        }
    }
    ll query(ll left,ll right){
        if(left>right)swap(left,right);
        return Q(1,0,N-1,left,right);
    }
};
const ll N=2e5+10;
ll timer=0;
seg S(N);
vector<ll>edges[N];
vector<ll>parent(N),val(N),depth(N),sz(N),pos(N),bigC(N),bigboss(N,-1);
void szdfs(ll source,ll P,ll D=0){
    depth[source]=D;
    parent[source]=P;
    sz[source]=1;
    ll bigchild=-1,bigsize=-1;
    for(ll x:edges[source]){
        if(x==P)continue;
        szdfs(x,source,D+1);
        sz[source]+=sz[x];
        if(sz[x]>bigsize){
            bigsize=sz[x];
            bigchild=x;
        }
    }
    bigC[source]=bigchild;
}
void decom(ll source,ll P){
    pos[source]=timer;
    timer++;
    S.upd(pos[source],val[source]);
    bigboss[source]=P;
    if(bigC[source]!=-1){
        decom(bigC[source],P);
    }
    for(ll x:edges[source]){
        if(x==parent[source]||x==bigC[source])continue;
        decom(x,x);
    }
}
ll Queyr(ll a,ll b){
    ll ans=-(1<<30);
    for(;bigboss[a]!=bigboss[b];b=parent[bigboss[b]]){
        if(depth[bigboss[a]]>depth[bigboss[b]])swap(a,b);
        ll cur=S.query(pos[bigboss[b]],pos[b]);
        ans=max(ans,cur);
    }
    if(depth[a]>depth[b])swap(a,b);
    ll cur=S.query(pos[a],pos[b]);
    ans=max(ans,cur);
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,q;cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>val[i];
    }
    for(ll i=0;i<n-1;i++){
        ll a,b;cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    szdfs(1,1);
    decom(1,1);
    while(q--){
        ll ch;cin>>ch;
        if(ch==1){
            ll a,b;cin>>a>>b;
            S.upd(pos[a],b);
        }else{
            ll a,b;cin>>a>>b;
            cout<<Queyr(a,b)<<" ";
        }
    }
}
