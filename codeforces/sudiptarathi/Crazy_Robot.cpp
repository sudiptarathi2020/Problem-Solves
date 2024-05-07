// https://codeforces.com/problemset/problem/1613/E
#include<bits/stdc++.h>
#include <utility>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(),(x.end())
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define sz(x) (x).size()
const ll inf=1LL<<60;
const ll mod=1e9+7;
using pii=std::pair<int,int>;
using pll=std::pair<ll,ll>;
using vl=std::vector<ll>;
using vi=std::vector<int>;
using seti=std::set<int>;
using setl=std::set<ll>;
using pq=std::priority_queue<ll>;
using namespace std;
void sol(int test_case);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}
vector<string>s;
ll n,m;
ll dx[]={-1,0,1,0};
ll dy[]={0,1,0,-1};
void dfs(ll sx,ll sy,ll px,ll py){
    ll cnt=0;
    for(ll i=0;i<4;i++){
        ll X=sx+dx[i];
        ll Y=sy+dy[i];
        if(make_pair(X,Y)!=make_pair(px,py) and X>=0 and X<n and Y>=0 and Y<m and s[X][Y]=='.'){
            cnt++;
        }
    }
    if(cnt>1)return;
    s[sx][sy]='+';
    for(ll i=0;i<4;i++){
        ll X=sx+dx[i];
        ll Y=sy+dy[i];
        if(make_pair(X,Y)!=make_pair(px,py) and X>=0 and X<n and Y>=0 and Y<m and s[X][Y]=='.'){
            dfs(X,Y,sx,sy);
        }
    }
}
void sol(int test_case){
    cin>>n>>m;
    s.resize(n);
    ll sx=-1,sy=-1;
    for(ll i=0;i<n;i++){
        cin>>s[i];
        for(ll j=0;j<m;j++){
            if(s[i][j]=='L'){
                sx=i,sy=j;
            }
        }
    }
    if(sx+1<n and s[sx+1][sy]=='.'){
        dfs(sx+1,sy,sx,sy);
    }
    if(sx-1>=0 and s[sx-1][sy]=='.'){
        dfs(sx-1,sy,sx,sy);
    }
    if(sy+1<m and s[sx][sy+1]=='.'){
        dfs(sx,sy+1,sx,sy);
    }
    if(sy-1>=0 and s[sx][sy-1]=='.'){
        dfs(sx,sy-1,sx,sy);
    }
    for(ll i=0;i<n;i++){
        cout<<s[i]<<'\n';
    }
}

