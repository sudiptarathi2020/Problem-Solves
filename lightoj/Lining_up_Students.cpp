
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
template<class T>
struct SEGMENT{
    int n;
    vector<T>tree;
    SEGMENT(){}
    SEGMENT(int _n){
        this->n=_n;
        tree.resize(4*n);
        build(1,0,n-1);
    }
    void build(int node,int start,int end){
        if(start==end){
            tree[node]=1;
        }else{
            int mid=(start+end)>>1,L=node<<1,R=L|1;
            build(L,start,mid);
            build(R,mid+1,end);
            tree[node]=tree[L]+tree[R];
        }
    }
    void upd(int pos){
        upd(1,0,n-1,pos);
    }
    void upd(int node,int start,int end,int pos){
        if(start==end){
            tree[node]=0;
        }else{
            int mid=(start+end)>>1,L=node<<1,R=L|1;
            if(pos<=mid){
                upd(L,start,mid,pos);
            }else{
                upd(R,mid+1,end,pos);
            }
            tree[node]=tree[L]+tree[R];
        }
    }
    int Q(int node,int start,int end,int sum){
        if(start==end){
            return start;
        }else{
            int mid=(start+end)>>1,L=node<<1,R=L|1;
            if(sum<=tree[L]){
                return Q(L,start,mid,sum);
            }else{
                return Q(R,mid+1,end,sum-tree[L]);
            }
        }
    }
    int ind(int sum){
        return Q(1,0,n-1,sum);
    }
    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm))+ sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
    int q(int left,int right){
        return sum(1,0,n-1,left,right);
    }
};
void sol(ll test){
    int n;cin>>n;
    vector<int>arr(n);
    SEGMENT<int>S(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=n-1;i>=0;i--){
        arr[i]=S.q(0,n-1)-arr[i];
        int pos=S.ind(arr[i]);
        S.upd(pos);
        if(i==0){
            cout<<"Case "<<test<<": "<<pos+1<<endl;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
}
