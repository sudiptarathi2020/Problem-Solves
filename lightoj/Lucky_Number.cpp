
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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
#define FORd(i,a,b) for(int i=a;i>=b;i--)
#define F0Rd(i,a) for(int i=a;i>=0;i--)
const ll N=1e5+1;
const ll MX=1429431+10;
using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll inf=LLONG_MAX;
const ll ninf=LLONG_MIN;
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
void sol(){

    return; 
}
int main(){
    ordered_set<ll>st;
    st.insert(0);
    for(ll i=1;i<MX;i+=2){
        st.insert(i);
    }
    vl tt(MX); 
    tt[1]=1;
    for(ll i=2;i<N;i++){
        if(i>=(ll)st.size()){
            break;
        }
        ll x=*st.find_by_order(i);
        vl v;
        for(ll u=x;u<MX;u+=x){
            if(u>=(ll)st.size()){
                break;
            }
            v.pb(*st.find_by_order(u));
        }
        for(ll x:v){
            st.erase(x);
        }
        tt[i]=x;
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    for(ll i=1;i<=t;i++){
        ll x;cin>>x;
        cout<<"Case "<<i<<": "<<tt[x]<<endl;
    }
    return 0;
}

