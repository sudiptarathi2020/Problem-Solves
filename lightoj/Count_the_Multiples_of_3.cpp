
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define mkp make_pair
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
#define IN cin
#define out cout
#define elif else if
#define yes cout<<"yes\n";
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define no cout<<"no\n";
#define fst first
#define scnd second
#define all(s) (s).begin(),(s.end())
#define sz(x) (ll)(x).size();
#define FOR(i,a,b) for(ll i=a;i<(b);i++)
#define F0R(i,a) for(ll i=0;i<(a);i++)
#define FORd(i,a,b) for(ll i=a;i>=b;i--)
#define F0Rd(i,a) for(ll i=a;i>=0;i--)
using namespace std;
const ll inf=LLONG_MAX;
const ll ninf=LLONG_MIN;
const ll N=1e5+10;
const ll mod=1e9+7;
typedef pair<ll,ll> pl;
typedef set<ll> st;
typedef queue<ll> ql;
typedef multiset<ll>mst;
typedef queue<pl> qpl;
typedef stack<ll> stk;
typedef stack<pl> stkp;
typedef priority_queue<ll> pq;
typedef priority_queue<ll,vector<ll>,greater<ll>> rpq;
typedef priority_queue<pl> pql;
typedef priority_queue<pl,vector<pl>,greater<pl>> rpql;
typedef set<pl> stp;
typedef vector<ll> vl;
typedef set<ll,greater<ll>> rst;
typedef set<pl,greater<pl>> rstp;
typedef vector<pl> vpl;
typedef vector<string> vs;
struct segtree{
    vector<array<ll,3>>tree;
    vector<ll>lazy;
    ll n;
    segtree(){}
    segtree(ll n){
        this->n=n;
        tree.assign(4*n,{0,0,0});
        lazy.assign(4*n,0);
    }
    void push(ll node,ll st,ll end){
        if(lazy[node]==1){
            tree[node][2]=tree[node][1];
            tree[node][1]=tree[node][0];
            tree[node][0]=(end-st)+1-tree[node][1]-tree[node][2];
        }
        if(lazy[node]==2){
            tree[node][1]=tree[node][2];
            tree[node][2]=tree[node][0];
            tree[node][0]=(end-st)+1-tree[node][1]-tree[node][2];
        }
        if(st!=end){
            lazy[node<<1]=(lazy[node<<1]+lazy[node])%3;
            lazy[(node<<1)|1]=(lazy[(node<<1)|1]+lazy[node])%3;
        }
        lazy[node]=0;
    }
    void build(){
        build(1,0,n-1);
    }
    void build(ll node,ll st,ll end){
        if(st==end){
            tree[node][0]=1;
            tree[node][1]=0;
            tree[node][2]=0;
            return;
        }
        ll mid=(st+end)>>1;
        build(node<<1,st,mid);
        build((node<<1)|1,mid+1,end);
        for(ll i=0;i<3;i++){
            tree[node][i]=tree[2*node][i]+tree[2*node+1][i];
        }
    }
    void update(ll l,ll r){
        update(1,0,n-1,l,r,1);
    }
    void update(int node, int st, int en, int l, int r, int val) {
  if (lazy[node] != 0) // if node is lazy then update it
  {
      push(node,st,en);
  }
  if ((en < l) || (st > r)) // case 1
  {
    return;
  }
  if (st >= l && en <= r) // case 2
  {
    tree[node][2]=tree[node][1];
    tree[node][1]=tree[node][0];
    tree[node][0]=(en-st)+1-tree[node][1]-tree[node][2];
    if (st != en) {
      lazy[2 * node] =(lazy[2*node]+1)%3; // mark its children lazy
      lazy[2 * node + 1]=(lazy[2*node+1]+1)%3;
    }
    return;
  }

  // case 3
  int mid = (st + en) / 2;

  // recursively call for updating left child
  update(2 * node, st, mid, l, r, val);
  // recursively call for updating right child
  update(2 * node + 1, mid + 1, en, l, r, val);

  for(ll i=0;i<3;i++){
      tree[node][i]=tree[2*node][i]+tree[2*node+1][i];
  }
}
    ll qur(ll l,ll r){
        return qr((ll)1,(ll)0,(ll)n-1,(ll)l,(ll)r);
    }
    ll qr(ll node, ll st, ll en, ll l, ll r) {
     if (lazy[node] != 0) {
     push(node,st,en);
    }
    if (en < l || st > r) {
     return 0;
     }

    if ((l <= st) && (en <= r)) {
     return tree[node][0];
     }
    ll mid = (st + en) / 2;

    ll q1 = qr(2 * node, st, mid, l, r);

    ll q2 = qr(2 * node + 1, mid + 1, en, l, r);

    return (q1 + q2);
}
};
void sol(ll test){
    ll n;IN>>n;
    ll q;IN>>q;
    segtree seg(n); 
    seg.build();
    out<<"Case "<<test<<": \n";
    while(q--){
        ll a,b,c;IN>>a>>b>>c;
        if(a==0){
            seg.update(b,c);
        }else{
            out<<seg.qur(b,c)<<endl; 
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}

