
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
const int N=200010;
int st[N],en[N],timer=0;
ll tree[N],arr[N];
vector<int>edges[N];
void dfs(int source,int parent){
    st[source]=timer;
    for(int x:edges[source]){
        if(x==parent)continue;
        timer++;
        dfs(x,source);
    }
    en[source]=timer;
}
ll query(int r){
    ll ret=0;
    for(;r>=0;r=(r&(r+1))-1){
        ret+=tree[r];
    }
    return ret;
}
ll query(int left,int right){
    return query(right)-query(left-1);
}
void upd(int pos,ll val){
    val-=query(pos,pos);
    for(int i=pos;i<=timer;i=i|(i+1)){
        tree[i]+=val;
    }
}
 
void sol(int test){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++){
        upd(st[i],arr[i]);
    }
    while(q--){
        int choice;cin>>choice;
        if(choice==1){
            int s;ll x;cin>>s>>x;
            upd(st[s],x);
        }else{
            int s;cin>>s;
            cout<<query(st[s],en[s])<<endl;
        }
    }
}
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
