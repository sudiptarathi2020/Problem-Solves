//https://codeforces.com/gym/100551/problem/A
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct dsu_save {
    int v, rnkv, u, rnku;

    dsu_save() {}

    dsu_save(int _v, int _rnkv, int _u, int _rnku)
        : v(_v), rnkv(_rnkv), u(_u), rnku(_rnku) {}
};

struct dsu_with_rollbacks {
    vector<int> p, rnk;
    int comps;
    stack<dsu_save> op;

    dsu_with_rollbacks() {}

    dsu_with_rollbacks(int n) {
        p.resize(n+1);
        rnk.resize(n+1);
        for (int i = 0; i <=n; i++) {
            p[i] = i;
            rnk[i] = 0;
        }
        comps = n;
    }

    int find_set(int v) {
        return (v == p[v]) ? v : find_set(p[v]);
    }

    bool unite(int v, int u) {
        v = find_set(v);
        u = find_set(u);
        if (v == u)
            return false;
        comps--;
        if (rnk[v] > rnk[u])
            swap(v, u);
        op.push(dsu_save(v, rnk[v], u, rnk[u]));
        p[v] = u;
        if (rnk[u] == rnk[v])
            rnk[u]++;
        return true;
    }

    void rollback() {
        if (op.empty())
            return;
        dsu_save x = op.top();
        op.pop();
        comps++;
        p[x.v] = x.v;
        rnk[x.v] = x.rnkv;
        p[x.u] = x.u;
        rnk[x.u] = x.rnku;
    }
};
struct segment{
    dsu_with_rollbacks d;
    vector<vector<pair<ll,ll>>>t;
    vector<ll>ans;
    ll Q;
    segment(){}
    segment(ll n,ll q){
        Q=q;
        ans.resize(q);
        t.resize(4*q);
        d=dsu_with_rollbacks(n);
    }
    void add(ll node,ll start,ll end,ll left,ll right,pair<ll,ll>x){
        if(start==left and end==right){
            t[node].push_back(x);
            return;
        }
        ll mid=(start+end)>>1;
        if(right<=mid){
            add(node<<1,start,mid,left,right,x);
        }else if(mid<left){
            add((node<<1)|1,mid+1,end,left,right,x);
        }else{
            add(node<<1,start,mid,left,mid,x);
            add((node<<1)|1,mid+1,end,mid+1,right,x);
        }
    }
    void add(pair<ll,ll>x,ll left,ll right){
        add(1,0,Q-1,left,right,x);
    }
    void dfs(ll node,ll start,ll end){
        if(end<start)return;
        ll k=0;
        for(pair<ll,ll>x:t[node]){
            k+=d.unite(x.first,x.second);
        }
        if(start==end){
            ans[start]=d.comps;
        }else{
            ll mid=(start+end)>>1;
            dfs(node<<1,start,mid);
            dfs((node<<1)|1,mid+1,end);
        }
        while(k--){
            d.rollback();
        }
    }
};
bool operator==(pair<ll,ll>a,pair<ll,ll>b){
    return a==b;
}
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return (hash1)^(hash2<<32);
    }
};
int main(){
    long long n,q;cin>>n>>q;
    segment s(n,q);
    vector<ll>ans;
    unordered_map<pair<ll,ll>,ll,hash_pair>mp;
    for(ll i=0;i<q;i++){
        char x;cin>>x;
        if(x=='+'){
            ll a,b;cin>>a>>b;
            if(a>b)swap(a,b);
            mp[make_pair(a,b)]=i;
        }else if(x=='-'){
            ll a,b;cin>>a>>b;
            if(a>b)swap(a,b);
            s.add(make_pair(a,b),mp[make_pair(a,b)],i-1);
            mp.erase(make_pair(a,b));
        }else if(x=='?'){
            ans.push_back(i);
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        s.add(it->first,it->second,q-1);
    }
    s.dfs(1,0,q-1);
    for(ll i:ans){
        cout<<s.ans[i]<<endl;
    }
}
