
#include<bits/stdc++.h>
#include <climits>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
const int N=100050,lg=19;
int value[N],st[N],en[N],level[N],timer=0;
vector<pair<int,pii>>father[N];
vector<int>edges[N];
void dfs(int source,int P=0){
    st[source]=timer++;
    father[source][0]={P,{value[P],P}};
    for(int i=1;i<lg;i++){
        father[source][i].first=father[father[source][i-1].first][i-1].first;
        father[source][i].second=max(father[source][i-1].second,father[father[source][i-1].first][i-1].second);
    }
    for(int x:edges[source]){
        if(x!=P){
            level[x]=level[source]+1;
            dfs(x,source);
        }
    }
    en[source]=timer++;
}
void init(int n){
    timer=0;
    for(int i=0;i<=n;i++){
        level[i]=0;
        st[i]=en[i]=0;
        edges[i].clear();
        father[i].clear();
        father[i].resize(lg);
        value[i]=0;
    }
}
void sol(int test){
    int n,q;cin>>n>>q;
    init(n);
    value[0]=1;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        edges[a].push_back(i);
        edges[i].push_back(a);
        value[i]=b;
    }
    dfs(0);
    cout<<"Case "<<test<<": \n";
    while(q--){
        int a,k;cin>>a>>k;
        for(int i=lg-1;i>=0;i--){
            if(value[father[a][i].first]>=k){
                a=father[a][i].first;
            }
        }
        cout<<a<<endl;
    }
}
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

