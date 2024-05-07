//https://codeforces.com/problemset/problem/1891/F
#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct seg{
    ll N;
    vector<ll>tree;
    vector<ll>lval;
    vector<bool>lazy;
    seg(){}
    seg(ll _N){
        rsz(_N);
    }
    void rsz(ll _N){
        N=_N;
        tree.clear();
        lval.clear();
        lazy.clear();
        tree.resize(N<<2);
        lval.resize(N<<2);
        lazy.resize(N<<2);
    }
    void push(ll node,ll start,ll end){
        if(lazy[node]){
            tree[node]+=(end-start+1)*lval[node];
            if(start!=end){
                lazy[node<<1]=lazy[node<<1|1]=true;
                lval[node<<1]+=lval[node];
                lval[node<<1|1]+=lval[node];
            }
            lval[node]=0,lazy[node]=false;
        }
    }
    void upd(ll node,ll start,ll end,ll left,ll right,ll val){
        push(node,start,end);
        if(start==left and end==right){
            tree[node]+=(end-start+1)*val;
            if(start!=end){
                lazy[node<<1]=lazy[node<<1|1]=true;
                lval[node<<1]+=val;
                lval[node<<1|1]+=val;
            }
            return;
        }
        ll mid=(start+end)>>1;
        if(right<=mid){
            upd(node<<1,start,mid,left,right,val);
        }else if(mid<left){
            upd(node<<1|1,mid+1,end,left,right,val);
        }else{
            upd(node<<1,start,mid,left,mid,val);
            upd(node<<1|1,mid+1,end,mid+1,right,val);
        }
        tree[node]=tree[node<<1]+tree[node<<1|1];
    }
    void upd(ll pos,ll val){
        upd(1,0,N-1,pos,pos,val);
    }
    void upd(ll left,ll right,ll val){
        upd(1,0,N-1,left,right,val);
    }
    ll query(ll pos){
        return query(1,0,N-1,pos,pos);
    }
    ll query(ll left,ll right){
        return query(1,0,N-1,left,right);
    }
    ll query(ll node,ll start,ll end,ll left,ll right){
        push(node,start,end);
        if(start==left and end==right){
            return tree[node];
        }
        ll mid=(start+end)>>1;
        if(right<=mid){
            return query(node<<1,start,mid,left,right);
        }else if(mid<left){
            return query(node<<1|1,mid+1,end,left,right);
        }else{
            ll a=query(node<<1,start,mid,left,mid);
            ll b=query(node<<1|1,mid+1,end,mid+1,right);
            return a+b;
        }
    }
};
seg S;
vector<vector<ll>>edges;
ll timer=0;
vector<ll>st,en;
void dfs(ll source,ll father){
    st[source]=timer;
    for(auto x:edges[source]){
        if(x==father)continue;
        timer++;
        dfs(x,source);
    }
    en[source]=timer;
}
void sol(){
    ll n;cin>>n;
    ll cnt=1;
    edges.clear();
    edges.resize(n+10);
    timer=0;
    S.rsz(n+10);
    st.clear();
    en.clear();
    st.resize(n+10);
    en.resize(n+10);
    vector<array<ll,3>>type;
    for(ll i=0;i<n;i++){
        ll ch;cin>>ch;
        if(ch==1){
            ll a;cin>>a;
            cnt++;
            edges[a].push_back(cnt);
            type.push_back({0,cnt,cnt});
        }else{
            ll a,b;cin>>a>>b;
            type.push_back({1,a,b});
        }
    }
    dfs(1,1);
    for(auto x:type){
        if(x[0]){
            S.upd(st[x[1]],en[x[1]],x[2]);
        }else{
            ll q=S.query(st[x[1]],st[x[1]]);
            S.upd(st[x[1]],en[x[1]],-q);
        }
    }
    for(ll i=1;i<=cnt;i++){
        cout<<S.query(st[i],st[i])<<" ";
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    while(t--)sol();
}
