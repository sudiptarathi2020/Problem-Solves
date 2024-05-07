//https://codeforces.com/problemset/problem/1785/B
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
void sol(ll test){
    int n;cin>>n;    
    vector<array<int,4>>ans;
    map<pair<char,char>,vector<int>>mp;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        vector<char>need,extra;
        map<char,int>cnt;
        for(char x:s[i]){
            cnt[x]++; 
        }
        for(char x:{'w','i','n'}){
            if(cnt[x]==0){
                need.push_back(x);
            }else{
                for(int j=1;j<cnt[x];j++){
                    extra.push_back(x);
                }
            }
        }
        for(int j=0;j<(int)need.size();j++){
            char x=need[j],y=extra[j];
            if(mp[mkp(y,x)].size()){
                ans.push_back({i,y,mp[mkp(y,x)].back(),x});
                mp[mkp(y,x)].pop_back();
            }else{
                mp[mkp(x,y)].push_back(i);
            }
        }
    }
    char x[3]={'w','i','n'};
    if(mp[mkp(x[0],x[1])].empty()){
        swap(x[0],x[1]);
    }
    for(int i=0;i<(int)mp[mkp(x[0],x[1])].size();i++){
        int xx=mp[mkp(x[0],x[1])][i];
        int yy=mp[mkp(x[1],x[2])][i];
        int zz=mp[mkp(x[2],x[0])][i];
        ans.push_back({xx,x[1],yy,x[2]});
        ans.push_back({zz,x[0],xx,x[2]});
    }
    cout<<(ans).size()<<endl;
    for(auto &x:ans){
        cout<<x[0]+1<<" "<<char(x[1])<<" "<<x[2]+1<<" "<<char(x[3])<<endl;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
}


