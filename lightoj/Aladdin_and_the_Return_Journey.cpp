#include<bits/stdc++.h>
const int inf=INT_MAX;
using namespace std;
struct LCA{
    int n,l;
    vector<vector<int>>adj;
    int timer;
    vector<int>tin,tout;
    vector<vector<int>>up;
    LCA(){}
    LCA(int _n){
        this->n=_n;
        this->timer=0;
        l=ceil(log2(n));
        adj.resize(n+1);
        tin.resize(n+1);
        tout.resize(n+1);
        up.assign(n,vector<int>(l+1));
    }
    void add(int a,int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void dfs(int v,int p){
        tin[v]=++timer;
        up[v][0]=p;
        for(int i=1;i<=l;++i){
            up[v][i]=up[up[v][i-1]][i-1];
        }
        for(int u:adj[v]){
            if(u!=p){
                dfs(u,v);
            }
        }
        tout[v]=++timer;
    }
    bool is_an(int u,int v){
        return tin[u]<=tin[v] and tout[u]>=tout[v];
    }
    int lca(int u,int v){
        if(is_an(u,v)){
            return u;
        }
        if(is_an(v,u)){
            return v;
        }
        for(int i=l;i>=0;i--){
            if(!is_an(up[u][i],v)){
                u=up[u][i];
            }
        }
        return up[u][0];
    }
    void pre(int root){
        dfs(root,root);
    }
};
struct HLD{
    vector<vector<int>>adj;
    vector<int>tree;
    vector<int>head,pos,heavy,depth,parent,sz;
    vector<bool>vis;
    vector<int>euler,gene;
    int n;
    HLD(){}
    HLD(int _n){
        this->n=_n;
        adj.resize(n);
        head.resize(n+1);
        gene.resize(n+1);
        vis.resize(n+1);
        sz.resize(n+1);
        pos.resize(n+1);
        heavy.resize(n+1,-1);
        tree.assign(4*n,0);
        depth.resize(n+1);
        parent.resize(n+1);
    }
    void add(int a,int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void decom(int source,int h){
        head[source]=h;
        pos[source]=(int)euler.size();
        euler.push_back(gene[source]);
        if(heavy[source]!=-1){
            decom(heavy[source],h);
        }
        for(int c:adj[source]){
            if(c!=parent[source] and c!=heavy[source]){
                decom(c,c);
            }
        }
    }
    void build(int node,int st,int en){
        if(st==en){
            tree[node]=euler[st];
        }else{
            int mid=(st+en)>>1;
            build(node+node,st,mid);
            build(node+1+node,mid+1,en);
            tree[node]=tree[2*node]+tree[2*node+1];
        }
    }
    void upd(int node,int st,int en,int ind,int val){
        if(st==en){
            tree[node]=val;
        }else{
            int mid=(st+en)>>1;
            if(ind<=mid){
                upd(node+node,st,mid,ind,val);
            }else{
                upd(node+node+1,mid+1,en,ind,val);
            }
            tree[node]=tree[2*node]+tree[2*node+1];
        }
    }
    void upd(int v,int val){
        upd(1,0,n-1,pos[v],val);
    }
    void make_seg(){
        build(1,0,n-1);
    }
    int q(int node,int st,int en,int left,int right){
        if(st==left and right==en){
            return tree[node];
        }
        int mid=(st+en)>>1;
        if(right<=mid){
            return q(node+node,st,mid,left,right);
        }else if(left>mid){
            return q(node+node+1,mid+1,en,left,right);
        }else{
            int a=q(node+node,st,mid,left,mid);
            int b=q(node+node+1,mid+1,en,mid+1,right);
            return a+b;
        }
    }
    int q(int left,int right){
        return q(1,0,n-1,left,right);
    }
    int query(int u,int v){
        int a=pos[u],b=pos[v];
        if(a<b){
            return q(a,b);
        }else{
            return q(b,a);
        }
    }
    void dfs(int source,int par,int H){
        vis[source]=true;
        depth[source]=H;
        parent[source]=par;
        sz[source]+=1; 
        int Mx=-1,big=-1;
        for(int u:adj[source]){
            if(u!=par){
                dfs(u,source,H+1);
                sz[source]+=sz[u];
                if(sz[u]>Mx){
                    Mx=sz[u];
                    big=u;
                }
            }
        }
        heavy[source]=big;
    }
    int get_ans(int a,int b){
        int res=0;
        for(;head[a]!=head[b];b=parent[head[b]]){
            if(depth[head[a]]>depth[head[b]]){
                swap(a,b);
            }
            int cur=query(head[b],b);
            res+=cur;
        }
        if(depth[a]>depth[b]){
            swap(a,b);
        }
        int cur=query(a,b);
        return res+cur;
    }
};
void sol(int test){
    int a,b,n,q;cin>>n;
    HLD H(n);
    for(int i=0;i<n;i++){
        cin>>H.gene[i];
    }
    for(int i=1;i<n;i++){
        cin>>a>>b;
        H.add(a,b);
    }
    H.dfs(0,0,0);
    H.decom(0,0);
    H.make_seg();
    ;cin>>q;
    cout<<"Case "<<test<<": \n";
    while(q--){
        int choice;cin>>choice;
        if(!choice){
            int a,b;cin>>a>>b;
            cout<<H.get_ans(a,b)<<endl;
        }else{
            int a,b;cin>>a>>b;
            H.upd(a,b);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
}
