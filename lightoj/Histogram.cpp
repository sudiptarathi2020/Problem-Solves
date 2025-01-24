
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
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
    vector<ll>tree;
    ll sst,ent;
    segtree(){}
    segtree(ll n){
        tree.assign(4*n,0);
        sst=0;ent=n-1;
    }
    void build(vector<ll>&v,ll node,ll st,ll en){
        if(st==en){
            tree[node]=v[st];
            return;
        }
        ll mid=(st+en)>>1;
        build(v,2*node,st,mid);
        build(v,2*node+1,mid+1,en);
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
    ll q(ll node,ll st,ll en,ll l,ll r){
        if(st==l and en==r){
            return tree[node];
        }
        if(l>r){
            return inf;
        }
        ll mid=(st+en)>>1;
        if(r<=mid){
            return q(2*node,st,mid,l,r);
        }else if(l>mid){
            return q(2*node+1,mid+1,en,l,r);
        }else{
            ll ans1=q(2*node,st,mid,l,mid);
            ll ans2=q(2*node+1,mid+1,en,mid+1,r);
            return min(ans1,ans2);
        }
    }
    void build(vector<ll>&v){
        build(v,1,sst,ent);
    }
    ll q(ll l,ll r){
        return q(1,sst,ent,l,r);
    }
};
void sol(int test){
    ll n;cin>>n;
    vl v(n);
    F0R(i,n){
        cin>>v[i];
    }
    segtree seg(n);
    seg.build(v);
    ll ans=ninf;
    F0R(i,n){
        ll left=0,right=i;
        while(left!=right){
            ll mid=(left+right)>>1;
            if(seg.q(mid,i)<v[i]){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        ll ans1=left;
        left=i,right=n-1;
        while(left!=right){
			ll mid=(left+right)>>1;
			if(seg.q(i,mid)<v[i]){
                right=mid;
            }else{
                left=mid+1;
            }
		}
        ll ans2=left;
        if(seg.q(i,ans2)<v[i]){
            ans2--;
        }
        ans=max(ans,seg.q(ans1,ans2)*(ans2-ans1+1));
    }
    cout<<"Case "<<test<<": "<<ans<<endl;
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}

