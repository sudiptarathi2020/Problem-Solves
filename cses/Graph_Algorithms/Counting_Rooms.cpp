#include<bits/stdc++.h>
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
//    cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}
int n,m;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
vector<string>s;
bool vis[1001][1001];
void dfs(int ii,int jj){
    vis[ii][jj]=true;
    for(int i=0;i<4;i++){
        int x=ii+dx[i];
        int y=jj+dy[i];
        if(x>=0 and x<n and y>=0 and y<m){
            if(s[x][y]=='.' and !vis[x][y]){
                dfs(x,y);
            }
        }
    }
}
void sol(int test_case){
    cin>>n>>m;
    s.resize(n);
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='.' and !vis[i][j]){
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout<<cnt<<endl;
}
