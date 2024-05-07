//https://codeforces.com/problemset/problem/1715/D
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
const int mod=1e9+7;
const int N=100010;
const int lg=31;
vector<pii>edges[N];
void sol(int test){
    int n,m;cin>>n>>m;
    int ans[n+1];
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++){
        for(int k=0;k<lg;k++){
            ans[i]|=(1<<k);
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        edges[a].push_back(pii(b,c));
        edges[b].push_back(pii(a,c));
    }
    for(int bit=0;bit<lg;bit++){
        for(int i=1;i<=n;i++){
            for(pii v:edges[i]){
                if((v.second&(1<<bit))==0){
                    if((ans[i]&(1<<bit))){
                        ans[i]^=(1<<bit);
                    }
                }else if((ans[i]&(1<<bit))==0 && (ans[v.first]&(1<<bit))==0){
                    cout<<"-1\n";
                    return;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if((ans[i]&(1<<bit))){
                ans[i]^=(1<<bit);
                for(pii v:edges[i]){
                    if((v.second&(1<<bit)) && (ans[v.first]&(1<<bit))==0){
                        ans[i]|=(1<<bit);
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    for(int i=1;i<=t;i++){
        sol(i);
    }
}

