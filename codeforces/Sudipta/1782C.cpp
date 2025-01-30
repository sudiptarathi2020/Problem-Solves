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
void sol(ll test){
    ll n;cin>>n;
    string s;cin>>s;
    vector<vl>arr(26);
    F0R(i,n){
        arr[(int)s[i]-'a'].pb(i);
    }
    vl order(26);
    iota(all(order),0);
    sort(all(order),[&](int a,int b){
            return arr[a].size()>arr[b].size();
            });
    ll best=0;
    string ans="";
    for(ll i=1;i<=26;i++){
        if(n%i==0){
            ll current=0;
            for(ll ii=0;ii<i;ii++){
                current+=min(n/i,(ll)arr[order[ii]].size());
            }
            if(current>best){
                best=current;
                vector<char>xtra;
                ans=string(n,' ');
                for(ll j=0;j<i;j++){
                   ll p=order[j]; 
                   for(ll k=0;k<n/i;k++){
                        if(k<(ll)arr[p].size()){
                            ans[arr[p][k]]=char(p+'a');
                        }else{
                            xtra.pb((char)p+'a');            
                        }
                   }
                }
                for(char& ch:ans){
                    if(ch==' '){
                        ch=xtra.back();
                        xtra.pop_back();
                    }
                }
            }
        }
    }
    cout<<n-best<<endl;
    cout<<ans<<endl;
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
 