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
ll wh(ll a,ll b){

    return ((a+1)/2)*((b+1)/2)+(a/2)*(b/2);
}
ll white(ll a,ll b,ll c,ll d){
    return wh(c,d)-wh(c,b-1)-wh(a-1,d)+wh(a-1,b-1);
}
ll black(ll a,ll b,ll c,ll d){
    return (c-a+1)*(d-b+1)-white(a,b,c,d);
}
void sol(){
    ll n,m;cin>>n>>m;
    ll wht=white(1,1,n,m);    
    ll bck=black(1,1,n,m);
    ll x,y,x1,y1;cin>>x>>y>>x1>>y1;
    ll xt,yt,xt1,yt1;cin>>xt>>yt>>xt1>>yt1;
    wht+=black(x,y,x1,y1);
    bck-=black(x,y,x1,y1);
    bck+=white(xt,yt,xt1,yt1);
    wht-=white(xt,yt,xt1,yt1);
    if(max(x,xt)<=min(x1,xt1) and max(y,yt)<=min(y1,yt1)){
        ll p=max(x,xt);
        ll q=min(x1,xt1);
        ll r=max(y,yt);
        ll s=min(y1,yt1);
        bck+=black(p,r,q,s);;
        wht=(n*m)-bck;
        cout<<wht<<" "<<bck<<endl;
    }else{
        cout<<wht<<" "<<bck<<endl;
    }
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
