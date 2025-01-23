
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int father[N],sz[N],cnt;
int root(int a){
    if(a==father[a])return a;
    return father[a]=root(father[a]);
}
bool same(int a,int b){
    return root(a)==root(b);
}
void merge(int a,int b){
    a=root(a),b=root(b);
    if(a==b)return;
    cnt--;
    if(sz[a]<sz[b])swap(a,b);
    father[b]=a;
    sz[a]+=sz[b];
}
void init(int n){
    cnt=n;
    for(int i=0;i<=n;i++){
        father[i]=i;
        sz[i]=1;
    }
}
int main(){
    int n,m;cin>>n>>m;
    init(n);
    vector<array<int,3>>Roads(m);
    for(auto &x:Roads){
        cin>>x[1]>>x[2]>>x[0];
    }
    long long ans=0;
    sort(Roads.begin(),Roads.end());
    for(auto x:Roads){
        if(same(x[1],x[2]))continue;
        merge(x[1],x[2]);
        ans+=(long long)x[0];
    }
    if(cnt==1){
        cout<<ans<<endl;
    }else{
        cout<<"IMPOSSIBLE\n";
    }
}
