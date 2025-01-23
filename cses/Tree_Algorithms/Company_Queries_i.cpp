
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
const int N=200050;
const int lg=20;
vector<int>edges[N];
vector<int>father[N];
void dfs(int source,int P){
    father[source][0]=P;
    for(int i=1;i<lg;i++){
        father[source][i]=father[father[source][i-1]][i-1];
    }
    for(int x:edges[source]){
        if(x^P)dfs(x,source);
    }
}
int Kth(int source,int k){
    for(int i=lg-1;i>=0;i--){
        if((1<<i)&k){
            source=father[source][i];
        }
    }
    return source;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int a,n,q;cin>>n>>q;
    for(int i=0;i<=n;i++){
        father[i].resize(lg);
    }
    for(int i=2;i<=n;i++){
        cin>>a;
        edges[a].push_back(i);
    }
    dfs(1,0);
    while(q--){
        int source,k;cin>>source>>k;
        int ans=Kth(source,k);
        if(ans==-1 or ans==0){
            cout<<-1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
    return 0;
}
