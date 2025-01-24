
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
const int N=100050,lg=18;
vector<pii>edges[N];
vector<pair<int,pii>>father[N];
int st[N],en[N],timer=0;
void init(int n){
    timer=0;
    for(int i=0;i<=n+1;i++){
        father[i].clear();
        father[i].resize(lg+1);
        edges[i].clear();
        st[i]=0;
        en[i]=0;
    }
}
void dfs(int source,int P,int value,int svalue){
    st[source]=timer++;
    father[source][0]=make_pair(P,make_pair(value,svalue));
    for(int i=1;i<lg;i++){
        father[source][i].first=father[father[source][i-1].first][i-1].first;
        father[source][i].second.first=max(father[source][i-1].second.first,father[father[source][i-1].first][i-1].second.first);
        father[source][i].second.second=min(father[source][i-1].second.second,father[father[source][i-1].first][i-1].second.second);
    }
    for(auto x:edges[source]){
        if(x.first==P)continue;
        dfs(x.first,source,x.second,x.second);
    }
    en[source]=timer++;
}
bool is(int a,int b){
    return st[a]<=st[b] and en[a]>=en[b];
}
int lca(int a,int b){
    if(is(a,b))return a;
    if(is(b,a))return b;
    for(int i=lg-1;i>=0;i--){
        if(!is(father[b][i].first,a)){
            b=father[b][i].first;
        }
    }
    return father[b][0].first;
}
pii min_max(int a,int b){
    pii ans={0,1e5+50};
    int c=lca(a,b);
    for(int i=lg-1;i>=0;i--){
        if(is(c,father[a][i].first)){
            ans.first=max(ans.first,father[a][i].second.first);
            ans.second=min(ans.second,father[a][i].second.second);
            a=father[a][i].first;
        }
    }
    if(a!=c){
        ans.first=max(ans.first,father[a][0].second.first);
        ans.second=min(ans.second,father[a][0].second.second);
    }
    for(int i=lg-1;i>=0;i--){
        if(is(c,father[b][i].first)){
            ans.first=max(ans.first,father[b][i].second.first);
            ans.second=min(ans.second,father[b][i].second.second);
            b=father[b][i].first;
        }
    }
    if(b!=c){
        ans.first=max(ans.first,father[b][0].second.first);
        ans.second=min(ans.second,father[b][0].second.second);

    }
    return ans;
}
void sol(int test){
    int n;cin>>n;
    init(n);
    for(int i=1;i<n;i++){
        int a,b,c;cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    dfs(1,1,0,1e5+50);
    int q;cin>>q;
    cout<<"Case "<<test<<": \n";
    while(q--){
        int a,b;cin>>a>>b;
        pii ans=min_max(a,b);
        cout<<ans.second<<" "<<ans.first<<" "<<endl;
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

