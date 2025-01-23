
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(),(x.end())
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define sz(x) (x).size()
const ll inf=1LL<<60;
const ll mod=1e9+7;
using pii=std::pair<ll,ll>;
using pll=std::pair<ll,ll>;
using vl=std::vector<ll>;
using vi=std::vector<ll>;
using seti=std::set<ll>;
using setl=std::set<ll>;
using pq=std::priority_queue<ll>;
using namespace std;
void sol(ll test_case);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
 
    ll t=1;
//    cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}
struct BIT{
    vector<ll>tree;
    ll n;
    BIT(){}
    BIT(ll _n){
        this->n=_n;
        tree.resize(n,0);
    }
    void set(ll index,ll val){
        val=val-sum(index,index);
        for(;index<n;index=index|(index+1)){
            tree[index]+=val;
        }
    }
    ll sum(ll l,ll r){
        if(l>r)swap(l,r);
        return sum(r)-sum(l-1);
    }
    ll sum(ll index){
        ll ret=0;
        for(;index>=0;index=(index&(index+1))-1){
            ret+=tree[index];
        }
        return ret;
    }
};
struct HLD{
    BIT bit;
    ll N,timer;
    vector<vector<ll>>edges;
    vector<ll>father,sz,bigchild,bigboss,pos,nodeval;
    HLD(){}
    HLD(ll _N){
        this->N=_N;
        bit=BIT(N);
        edges.resize(N);
        timer=0;
        father.resize(N,-1);
        sz.resize(N,0);
        bigchild.resize(N,-1);
        bigboss.resize(N,-1);
        pos.resize(N);
        nodeval.resize(N);
    }
    void add(ll a,ll b){
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    void dfs(ll source,ll parent){
        father[source]=parent;
        sz[source]=1;
        ll big=-1;
        for(ll x:edges[source]){
            if(x==parent)continue;
            dfs(x,source);
            sz[source]+=sz[x];
            if(sz[x]>big){
                big=sz[x];
                bigchild[source]=x;
            }
        }
    }
    void decompose(ll source,ll head){
        bigboss[source]=head;
        pos[source]=timer;timer++;
        bit.set(pos[source],nodeval[source]);
        if(bigchild[source]!=-1){
            decompose(bigchild[source],head);
        }
        for(ll x:edges[source]){
            if(x==father[source])continue;
            if(x==bigchild[source])continue;
            decompose(x,x);
        }
    }
    void upd(ll source,ll val){
        bit.set(pos[source],val);
    }
    ll get_sum(ll source){
        ll res=0;
        for(;bigboss[source]!=bigboss[0];source=father[bigboss[source]]){
            res+=bit.sum(pos[bigboss[source]],pos[source]);
        }
        res+=bit.sum(pos[source],pos[0]);
        return res;
    }
};
void sol(ll test_case){
    int n,q;cin>>n>>q;
    HLD H(n);
    for(int i=0;i<n;i++)cin>>H.nodeval[i];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;a--,b--;
        H.add(a,b);
    }
    H.dfs(0,0);
    H.decompose(0,0);
    while(q--){
        int ch;cin>>ch;
        if(ch==1){
            int a,b;cin>>a>>b;
            a--;H.upd(a,b);
        }else{
            int a;cin>>a;a--;
            cout<<H.get_sum(a)<<endl;
        }
    }
}
