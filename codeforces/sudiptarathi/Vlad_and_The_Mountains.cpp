//https://codeforces.com/problemset/problem/1851/G
#include<bits/stdc++.h>
using namespace std;
template<typename T>struct dsu{
    T N;
    vector<T>par;
    vector<T>Sz;
    dsu(){}
    void rsz(T _N){
        this->N=_N+1;
        par.resize(N+1);
        Sz.resize(N+1,1);
        iota(par.begin(),par.end(),0);
    }
    T find(T A){
        if(A==par[A]){
            return A;
        }else{
            return par[A]=find(par[A]);
        }
    }
    void add(T A,T B){
        A=find(A),B=find(B);
        if(A==B)return;
        if(Sz[A]<Sz[B])swap(A,B);
        par[B]=A;
        Sz[A]+=Sz[B];
    }
    bool same(T A,T B){
        return find(A)==find(B);
    }
};
void sol(){
    int n;cin>>n;
    int m;cin>>m;
    dsu<int>D;
    D.rsz(n+1);
    vector<int>edges[n];
    vector<pair<int,int>>H(n);
    for(int i=0;i<n;i++){
        cin>>H[i].first;
        H[i].second=i;
    }
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a--,b--;
        if(H[a].first<H[b].first){
            edges[b].push_back(a);
        }else{
            edges[a].push_back(b);
        }
    }
    int Q;cin>>Q;
    vector<pair<pair<int,int>,pair<int,int> >>v(Q);
    for(int i=0;i<Q;i++){
        cin>>v[i].second.first>>v[i].second.second>>v[i].first.first;
        v[i].second.first--;
        v[i].second.second--;
        v[i].first.first+=H[v[i].second.first].first;
        v[i].first.second=i;
    }
    vector<string>ans(Q);
    sort(H.begin(),H.end());
    sort(v.begin(),v.end());
    int ind=0;
    for(auto x:v){
        while(ind<n and x.first.first>=H[ind].first){
            for(int K:edges[H[ind].second]){
                D.add(K,H[ind].second);
            }
            ind++;
        }
        ans[x.first.second]=D.same(x.second.first,x.second.second)?"YES":"NO";
    }
    for(string x:ans){
        cout<<x<<endl;
    }
}
int main(){
    int t;cin>>t;while(t--)sol();
}
