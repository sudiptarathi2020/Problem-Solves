//https://codeforces.com/problemset/problem/1806/E
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<ll,ll>;
using namespace std;
const ll mod=1e9+7,N=100050,lg=18;
vector<ll>edges[N],sp[N],st(N),en(N),value(N),layer(N),up(N),euler;
void dfs(ll source,ll P){
    up[source]+=value[source]*value[source];
    sp[source][0]=P;
    st[source]=(ll)euler.size();
    euler.push_back(source);
    for(ll i=1;i<lg;i++){
        sp[source][i]=sp[sp[source][i-1]][i-1];
    }
    for(ll x:edges[source]){
        if(x^P){
            up[x]=up[source];
            layer[x]=layer[source]+1;
            dfs(x,source);
        }
    }
    en[source]=(ll)euler.size();
    euler.push_back(source);
}
bool is_an(ll a,ll b){
    return st[a]<=st[b] and en[a]>=en[b];
}
ll lca(ll a,ll b){
    if(is_an(a,b))return a;
    if(is_an(b,a))return b;
    for(ll i=lg-1;i>=0;i--){
        if(!is_an(sp[a][i],b)){
            a=sp[a][i];
        }
    }
    return sp[a][0];
}
void clear(ll n){
    euler.clear();
    for(ll i=0;i<=n;i++){
        layer[i]=0;
        value[i]=0;
        edges[i].clear();
        sp[i].clear();
        sp[i].resize(lg);
        st[i]=0,en[i]=0;
    }
}
struct query{
    ll L,R,U,V,idx;
    query(){}
    query(ll _L,ll _R,ll _U,ll _V,ll _idx){
        L=_L,R=_R,U=_U,V=_V,idx=_idx;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,q;cin>>n>>q;
    clear(n);
    for(ll i=1;i<=n;i++){
        cin>>value[i];
    }
    ll father[n+1];father[1]=0;
    for(ll i=2;i<=n;i++){
        cin>>father[i];
        edges[father[i]].push_back(i);
    }
    dfs(1,1);
    vector<query>Q(q);
    for(ll i=0;i<q;i++){
        ll a,b;cin>>a>>b;
        if(st[a]>st[b])swap(a,b);
        Q[i].idx=i,Q[i].U=a,Q[i].V=b,Q[i].L=en[a],Q[i].R=st[b];
    }
    ll block_size=sqrt(n)+1;
    sort(Q.begin(),Q.end(),[&](query a,query b){
            return make_pair(a.L/block_size,a.R)<make_pair(b.L/block_size,b.R);
            });
    ll ans=0;
    vector<bool>vis(n+1);
    vector<ll>cntL(n+1),prod(n+1,1);
    auto add=[&](ll u){
        ll d=layer[u];
        cntL[d]++;
        prod[d]*=value[u];
        if(cntL[d]==2){
            ans+=(ll)prod[d];
        }
    };
    auto sub=[&](ll u){
        ll d=layer[u];
        if(cntL[d]==2){
            ans-=(ll)prod[d];
        }
        cntL[d]--;
        prod[d]/=value[u];
    };
    auto touch=[&](ll u){
        if(vis[u]){
            sub(u);
        }else{
            add(u);
        }
        vis[u]=!vis[u];
    };
    vector<ll>Ans(q);
    ll cur_l=0,cur_r=0;
    for(ll i=1;i<=n;i++){
    }
    for(query q:Q){
        if(q.U==q.V){
            Ans[q.idx]=up[q.U];
            continue;
        }
        ll l=q.L,r=q.R+1;
        while(cur_l>l){
            touch(euler[--cur_l]);
        }
        while(cur_r<r){
            touch(euler[cur_r++]);
        }
        while(cur_l<l){
            touch(euler[cur_l++]);
        }
        while(cur_r>r){
            touch(euler[--cur_r]);
        }
        ll c=lca(q.U,q.V);
        ll cur_sum=ans+up[c];
        if(vis[c]){
            cur_sum-=value[c]*value[c];
        }
        Ans[q.idx]=cur_sum;
    }
    for(ll i=0;i<q;i++){
        cout<<Ans[i]<<" ";
    }
}
