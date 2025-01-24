
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
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define FORd(i,a,b) for(int i=a;i>=b;i--)
#define F0Rd(i,a) for(int i=a;i>=0;i--)
using namespace std;
const ll inf=LLONG_MAX;
const ll ninf=LLONG_MIN;
const ll N=2e5;
const ll mod=1e9+7;
typedef pair<ll,ll> pl;
typedef set<ll> st;
typedef queue<ll> ql;
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
struct treetree{
    vl tree,lval;
    vector<bool>lazy;
    ll n;
    treetree(){}
    treetree(ll nn){
        this->n=nn;
        tree.assign(4*n,0);
        lval.assign(4*n,0);
        lazy.assign(4*n,0);
    }
    void update(ll x,ll y,ll v){
        update(1,0,n-1,x,y,v);
    }
    ll q(ll x,ll y){
        return query(1,0,n-1,x,y);
    }
    void update(int node, int st, int en, int l, int r, int val) {
  if (lazy[node] != 0) // if node is lazy then update it
  {
    tree[node] = (en - st + 1) * lval[node];

    if (st != en) // if its children exist then mark them lazy
    {
      lazy[2 * node] = true;
      lazy[2 * node + 1] =true;
      lval[2*node]=lval[node];
      lval[2*node+1]=lval[node];
    }
    lazy[node] = 0; // No longer lazy
    lval[node]=0;
  }
  if ((en < l) || (st > r)) // case 1
  {
    return;
  }
  if (st >= l && en <= r) // case 2
  {
    tree[node] = (en - st + 1) * val;
    if (st != en) {
      lazy[2 * node] =true; // mark its children lazy
      lazy[2 * node + 1] =true;
      lval[2*node]=val;
      lval[2*node+1]=val;
    }
    return;
  }

  // case 3
  int mid = (st + en) / 2;

  // recursively call for updating left child
  update(2 * node, st, mid, l, r, val);
  // recursively call for updating right child
  update(2 * node + 1, mid + 1, en, l, r, val);

  // Updating the parent with the values of the left and right child.
  tree[node] = (tree[2 * node] + tree[2 * node + 1]);
}
int query(int node, int st, int en, int l, int r) {
  /*If the node is lazy, update it*/
  if (lazy[node] != 0) {

    tree[node] = (en - st + 1) * lval[node];
    if (st != en) //Check if the child exist
    {
      // mark both the child lazy
      lazy[2 * node]=true;
      lazy[2 * node + 1]=true;
      lval[2*node]=lval[node];
      lval[2*node+1]=lval[node];
    }
    // no longer lazy
    lazy[node] = 0;
  }
  // case 1
  if (en < l || st > r) {
    return 0;
  }

  // case 2
  if ((l <= st) && (en <= r)) {
    return tree[node];
  }
  int mid = (st + en) / 2;

  //query left child
  ll q1 = query(2 * node, st, mid, l, r);

  // query right child
  ll q2 = query(2 * node + 1, mid + 1, en, l, r);

  return (q1 + q2);
}

};
void sol(ll test){
    ll n;cin>>n;
    ll q;cin>>q;
    vl v(n);
    treetree tree(n);
    cout<<"Case "<<test<<": \n";
    while(q--){
        ll ch;cin>>ch;
        if(ch==1){
            ll a,b,c;cin>>a>>b>>c;
            tree.update(a,b,c);

        }else{
            ll a,b;cin>>a>>b;
            ll c=tree.q(a,b);
            if(c%(b-a+1)==0){
                cout<<c/(b-a+1)<<endl;
                continue;
            }
            ll g=__gcd(c,b-a+1);
            cout<<c/g<<"/"<<(b-a+1)/g<<endl;

        }
    }
    return; 
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

