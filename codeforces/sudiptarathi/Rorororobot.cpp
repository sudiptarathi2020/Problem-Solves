//https://codeforces.com/problemset/problem/1709/D
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
    vl tree;
    ll n;
    seg(){}
    seg(ll _n){
        this->n=_n;
        tree.assign(4*n,(ll)0);
    }
    seg(vl &v){
        this->n=(ll)v.size();
        tree.assign(4*n,(ll)0);
        build(1,0,n-1,v);
    }
    void build(ll node,ll st,ll en,vl &v){
        if(st==en){
            tree[node]=v[st];
        }else{
            ll mid=(st+en)>>1;
            build(node<<1,st,mid,v);
            build(node+node+1,mid+1,en,v);
            tree[node]=max(tree[node<<1],tree[node+node+1]);
        }
    }
    ll q(ll node,ll st,ll en,ll left,ll right){
        if(st==left and en==right){
            return tree[node];
        }else{
            ll mid=(st+en)>>1;
            if(right<=mid){
                return q(node<<1,st,mid,left,right);
            }else if(left>mid){
                return q(node+node+1,mid+1,en,left,right);
            }else{
                ll a=q(node<<1,st,mid,left,mid);
                ll b=q(node+node+1,mid+1,en,mid+1,right);
                return max(a,b);
            }
        }
    }
    ll q(ll st,ll en){
        if(st>en)swap(st,en);
        return q(1,0,n-1,st-1,en-1);
    }
};
void sol(ll test){
    ll n,m,q,x1,y1,x2,y2,k;IN>>n>>m;
    vl arr(m);
    for(auto &x:arr)IN>>x;
    seg s(arr);
    IN>>q;
    while(q--){
        IN>>x1>>y1>>x2>>y2>>k;
        if(abs(y1-y2)%k or abs(x1-x2)%k){
            NO
        }else{
            ll j=n-x1;
            ll mx=s.q(y1,y2); 
            mx-=x1;
            ll p=(j/k)*k;
            if(p>mx){
                YES
            }else{
                NO
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}
/*
 * AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
 * AAAAAAAAA00000AAAAAA000AAAAA00000AAA
 * AAA00AAAA00000AA00A0000AA00A000000AA
 * A0A00AA0A000000A00A0000A000A0000000A
 * A0A00AA0A000000A00A0000A000A0000000A
 * 00A00AA00000000A00000000000000000000
 * 000000000000000000000000000000000000
 * */
