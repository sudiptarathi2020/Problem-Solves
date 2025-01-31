#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mkp make_pair
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
void sol(){
    ll n;cin>>n;
    vs s(n);
    set<string>ss[3];
    F0R(i,26){
        string x="";
        char c='a'+i;
        x+=c;
        ss[0].insert(x);
    }
    F0R(i,26){
        F0R(j,26){
            string x="";
            char c='a'+i;
            char cc='a'+j;
            x+=c;x+=cc;
            ss[1].insert(x);
        }
    }
    F0R(i,26){
        F0R(j,26){
            F0R(k,26){
                string x="";
                char c='a'+i;
                char cc='a'+j;
                char ccc='a'+k;
                x+=c,x+=cc,x+=ccc;
                ss[2].insert(x);
            }
        }
    }
    F0R(i,n){
        cin>>s[i];
        for(char x:s[i]){
            string y="";
            y+=x;
            if(ss[0].find(y)!=ss[0].end()){
                ss[0].erase(ss[0].find(y));
            }
        }
        for(int j=0;j<(int)s[i].size()-1;j++){
            string y="";
            y+=s[i][j],y+=s[i][j+1];
            if(ss[1].find(y)!=ss[1].end()){
                ss[1].erase(ss[1].find(y));
            }
        }
        for(int j=0;j<(int)s[i].size()-2;j++){
            string y="";
            y+=s[i][j],y+=s[i][j+1],y+=s[i][j+2];
            if(ss[2].find(y)!=ss[2].end()){
                ss[2].erase(ss[2].find(y));
            }
        }

    }
    if(ss[0].size()){
        cout<<*(ss[0].begin())<<endl;
        return ;
    }
    if(ss[1].size()){
        cout<<*(ss[1].begin())<<endl;
        return;
    }
    cout<<*(ss[2].begin())<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;//cin>>t;
    while(t--)sol();
    return 0;
}
