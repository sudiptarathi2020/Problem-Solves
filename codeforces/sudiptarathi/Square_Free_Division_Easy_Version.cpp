//https://codeforces.com/problemset/problem/1497/E1
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
const ll N=1e7+1;;
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
vector<int>prms(N+1);
int get(int num){
    int ans=1;
    while(num>1){
        int p=prms[num];
        int cnt=0;
        while(num%p==0){
            num/=p;
            cnt++;
        }
        if(cnt&1){
            ans*=p;
        }
    }
    return ans;
}
void sol(ll test){
    ll n;cin>>n;    
    ll k;cin>>k;
    assert(k==0);
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]=get(arr[i]);
    }
    set<int>st;
    int ans=1;
    for(int i=0;i<n;i++){
        if(st.empty()){
            st.insert(arr[i]);
            continue;
        }
        if(st.count(arr[i])){
            ans++;
            st.clear();
            st.insert(arr[i]);
        }else{
            st.insert(arr[i]);
        }
    }
    cout<<ans<<endl;
    return;
}
int main(){
    iota(all(prms),0);
    for(int i=2;i*i<=N;i++){
        if(prms[i]==i){
            for(int j=i*i;j<=N;j+=i){
                prms[j]=min(prms[j],i);
            }
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
}


