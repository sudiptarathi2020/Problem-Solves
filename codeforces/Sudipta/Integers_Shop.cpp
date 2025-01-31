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
struct node{
    ll first;
    ll second;;
    ll third;
    node(){}
    node(ll _first,ll _second,ll _third){
        first=_first;
        second=_second;
        third=_third;
    }
};
struct cmp{
    bool operator()(node a,node b)const
    {
        if(a.first<b.first){
            return true;
        }else if(a.first>b.first){
            return false;
        }else{
            if(a.second<b.second){
                return true;
            }else if(a.second>b.second){
                return false;
            }else{
                return a.third>b.third;
            }

        }
    }
};
struct cmp1{
    bool operator()(node a,node b)const
    {
        if(a.first>b.first){
            return true;
        }else if(a.first<b.first){
            return false;
        }else{
            if(a.second<b.second){
                return true;
            }else if(a.second>b.second){
                return false;
            }else{
                return a.third<b.third;
            }
        }
    }
};
struct cmp2{
    bool operator()(node a,node b)const
    {
        if(a.first<b.first){
            return true;
        }else if(a.first>b.first){
            return false;
        }else{
            if(a.second>b.second){
                return true;
            }else if(a.second<b.second){
                return false;
            }else{
                return a.third<b.third;
            }
        }
    }
};
void sol(){
    ll n;cin>>n;
    vector<pair<ll,pl>>v(n);
    set<node,cmp>t1; 
    set<node,cmp1>t2;
    set<node,cmp2>t3;
    F0R(i,n){
        cin>>v[i].fst>>v[i].scnd.fst>>v[i].scnd.scnd;  
        t1.insert(node(v[i].fst,v[i].scnd.scnd,v[i].scnd.fst)); 
        t2.insert(node(v[i].scnd.fst,v[i].scnd.scnd,v[i].fst));
        t3.insert(node(v[i].fst,v[i].scnd.fst,v[i].scnd.scnd));
        node it1=*t1.begin();
        node it2=*t2.begin();
        node it3=*t3.begin();
        ll ans=it1.second+it2.second;
        if(it3.second==it2.first){
            ans=min(ans,it3.third);
        }
        cout<<ans<<endl;
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
