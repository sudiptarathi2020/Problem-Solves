
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define mkp make_pair
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
#define fst first
#define scnd second
#define all(s) (s).begin(),(s.end())
#define sz(x) (ll)(x).size();
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define f0rd(i,a) for(int i=a;i>=0;i--)
using namespace std;
const ll inf=LLONG_MAX;
const ll ninf=LLONG_MIN;
typedef pair<ll,ll> pl;
typedef set<ll> st;
typedef queue<ll> ql;
typedef queue<pl> qpl;
typedef stack<ll> stk;
typedef stack<pl> stkp;
typedef priority_queue<ll> pq;
typedef priority_queue<pl> pql;
typedef set<pl> stp;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<string> vs;
struct segtree{
    vector<int>tree;
    vector<int>lazy;
    segtree(int n){
        tree.assign(4*n,0);
        lazy.assign(4*n,0);
    }
    void build(int arr[],int node,int st,int en){
        if(st==en){
            tree[node]=arr[st];
            return;
        }
        int mid=(st+en)/2;
        build(arr,2*node,st,mid);
        build(arr,2*node+1,mid+1,en);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    void update(int node,int st,int en,int l,int r,int val){
        if(lazy[node]!=0){
            tree[node]+=(en-st+1)*lazy[node];
            if(st!=en){
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }
            lazy[node]=0;
        }
        if(en<l||st>r){
            return ;
        }
        if(st>=l and en<=r){
            tree[node]+=(en-st+1)*val;
            if(st!=en){
                lazy[2*node]+=val;
                lazy[2*node+1]+=val;
            }
            return;
        }
        int mid=(st+en)/2;
        update(2*node,st,mid,l,r,val);
        update(2*node+1,mid+1,en,l,r,val);
        tree[node]=tree[node*2]+tree[2*node+1];
    }
    int query(int node,int st,int en,int l,int r){
        if(lazy[node]!=0){
            tree[node]+=(en-st+1)*lazy[node];
            if(st!=en){
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }
            lazy[node]=0;
        }
        if(en<l||st>r){
            return 0;
        }
        if(l<=st && en<=r){

            return tree[node];
        }
        int mid=(st+en)/2;
        int q=query(2*node,st,mid,l,r);
        int qq=query(2*node+1,mid+1,en,l,r);
        return q+qq;
    }
};
void sol(int test){
    string s;cin>>s;
    int len=(int)s.size();
    int arr[len+1];
    memset(arr,0,sizeof(arr));
    segtree seg(len+1);
    seg.build(arr,1,1,len);
    int q;cin>>q;
    cout<<"Case "<<test<<": "<<endl;
    while(q--){
        char c;cin>>c;
        if(c=='I'){
            int a,b;cin>>a>>b;
            seg.update(1,1,len,a,b,1);
        }else{
            int a;cin>>a;
            int ans=seg.query(1,1,len,a,a);
            if(ans&1){
                if(s[a-1]=='0'){
                    cout<<1<<endl;
                }else{
                    cout<<0<<endl;
                }
            }else{
                cout<<s[a-1]<<endl;    
            }
        }
    }
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}

