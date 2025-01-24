
#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int parent[N],sz[N];
void make(int n){
    for(int i=0;i<=n;i++){
        parent[i]=i,sz[i]=1;
    }
}
int root(int A){
    if(parent[A]==A)return A;
    return parent[A]=root(parent[A]);
}
void merge(int A,int B){
    A=root(A),B=root(B);
    if(A==B)return;
    if(sz[A]<sz[B])swap(A,B);
    parent[B]=A;sz[A]+=sz[B];
}
bool same(int A,int B){return root(A)==root(B);}
void sol(int test){
    int N,M,A;cin>>N>>M>>A;
    make(N);
    pair<pair<int,int>,int> edges[M];
    for(pair<pair<int,int>,int>&x:edges){
        cin>>x.first.first>>x.first.second>>x.second;
    }
    int ans=0,comp=N;
    sort(edges,edges+M,[](auto A,auto B){return A.second<B.second;});
    for(auto x:edges){
        if(x.second<A){
            if(!same(x.first.first,x.first.second)){
                merge(x.first.first,x.first.second);
                ans+=x.second;
                comp--;
            }
        }else{
            break;
        }
    }
    cout<<"Case "<<test<<": "<<ans+comp*A<<" "<<comp<<endl;
}
int main(){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
}
