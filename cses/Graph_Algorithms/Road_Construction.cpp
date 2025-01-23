#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int parent[N],sz[N],comp;
int root(int a){
    if(parent[a]==a)return a;
    return parent[a]=root(parent[a]);
}
void add(int a,int b){
    a=root(a),b=root(b);
    if(a==b)return;
    comp--;
    if(sz[a]<sz[b])swap(a,b);
    parent[b]=a;
    sz[a]+=sz[b];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    for(int i=0;i<N;i++){
        parent[i]=i;
        sz[i]=1;
    }
    int n;cin>>n;comp=n;
    int m,a,b;cin>>m;
    int Mx=1;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        add(a,b);
        Mx=max(Mx,sz[root(a)]);
        cout<<comp<<" "<<Mx<<endl;
    }
    return 0;
}
