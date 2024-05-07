//https://codeforces.com/problemset/problem/1833/E
#include<bits/stdc++.h>
using namespace std;
struct DSU{
    int n;
    vector<int>parent,sz;
    DSU(){}
    DSU(int _n){
        this->n=_n;
        parent.resize(n);
        sz.resize(n,1);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int a){
        if(parent[a]==a)return parent[a];
        return parent[a]=find(parent[a]);
    }
    void add(int a,int b){
        a=find(a),b=find(b);
        if(a==b)return;
        if(sz[a]<sz[b])swap(a,b);
        parent[b]=a;sz[a]+=sz[b];
    }
    bool same(int a,int b){
        return find(a)==find(b);
    }
};
void sol(){
    int n;cin>>n;
    DSU D(n);
    vector<int>A(n);
    for(int i=0;i<n;i++){
        cin>>A[i],A[i]--;
        D.add(A[i],i);
    }
    set<int>st;
    for(int i=0;i<n;i++){
        st.insert(D.find(i));
    }
    int mx=st.size();
    int count=0;
    for(int i=0;i<n;i++){
        if(i==A[A[i]])count++;
    }
    int mn=mx-count/2+1;
    cout<<min(mn,mx)<<" "<<mx<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;while(t--)sol();
    return 0;
}
