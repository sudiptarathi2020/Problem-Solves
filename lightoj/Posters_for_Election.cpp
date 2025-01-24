
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
struct seg{
    vl tree,lval;
    ll n;
    vector<bool>lz;
    seg(){}
    seg(ll nn){
        this->n=nn;
        tree.assign(4*n,0);
        lval.assign(4*n,0);
        lz.assign(4*n,0);
    }
    void U(ll node,ll st,ll en,ll x,ll y,ll val){
        if(lz[node]){
            tree[node]=lval[node];
            if(st!=en){
                lz[node<<1]=lz[(node<<1)|1]=true;
                lval[node<<1]=lval[(node<<1)|1]=lval[node];
            }
            lz[node]=false;
            lval[node]=0;
        }
        if(st==x and en==y){
            tree[node]=val;
            if(st!=en){
                lz[node<<1]=lz[(node<<1)|1]=true;
                lval[node<<1]=lval[(node<<1)|1]=val;
            }
            return;
        }
        ll mid=(st+en)>>1;
        if(y<=mid){
            U(node<<1,st,mid,x,y,val);
        }else if(x>mid){
            U((node<<1)|1,mid+1,en,x,y,val);
        }else{
            U(node<<1,st,mid,x,min(mid,y),val);
            U((node<<1)|1,mid+1,en,max(mid+1,x),y,val);
        }
        tree[node]=min(tree[node<<1],tree[(node<<1)|1]);
    }
    void upd(ll st,ll en,ll val){
        U(1,0,n-1,st,en,val);
    }
    ll Q(ll node,ll st,ll en,ll pos){
        if(lz[node]){
            tree[node]=lval[node];
            if(st!=en){
                lz[node<<1]=lz[(node<<1)|1]=true;
                lval[node<<1]=lval[(node<<1)|1]=lval[node];
            }
            lz[node]=false;
            lval[node]=0;
        }
        if(st==en){
            return tree[node];
        }
        ll mid=(st+en)>>1;
        if(pos<=mid){
            return Q(node<<1,st,mid,pos);
        }else{
            return Q((node<<1)|1,mid+1,en,pos);
        }
    }
    ll q(ll i){
        return Q(1,0,n-1,i);
    }
};
void sol(ll test){
    ll n;cin>>n;
    seg s((n<<1)|1);
    for(ll i=1;i<=n;i++){
        ll a,b;cin>>a>>b;
        s.upd(a,b,i);
    }
    set<ll>stj;
    for(ll i=1;i<=n<<1;i++){
        ll p=s.q(i);
        if(p!=0){
            stj.insert(p);
        }
    }
    cout<<"Case "<<test<<": "<<(ll)stj.size()<<endl;
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;cin>>t;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}

