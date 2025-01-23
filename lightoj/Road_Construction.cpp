
#include<bits/stdc++.h>
using namespace std;
const int N=200000;
class DSU{
    private:
        int n;
        vector<int>parent,sz;
    public:
    DSU(int _n){
        this->n=_n;
        parent.resize(n+1);
        sz.resize(n+1,1);
        iota(parent.begin(),parent.end(),0);
    }
    int find(int a){
        if(parent[a]==a){
            return a;
        }
        return parent[a]=find(parent[a]);
    }
    void unite(int a,int b){
        a=find(a),b=find(b);
        if(a==b)return;
        if(sz[a]<sz[b])swap(a,b);
        sz[a]+=sz[b];
        parent[b]=a;
    }
    bool same(int a,int b){
        return find(a)==find(b);
    }
    int get_size(int a){
        return sz[find(a)];
    }
};
void sol(int test){
    int n;cin>>n;
    int cnt=0;
    set<string>st;
    vector<pair<int,pair<string,string>>>vt;
    for(int i=0;i<n;i++){
        string a,b;int cost;
        cin>>a>>b>>cost;
        st.insert(a);
        st.insert(b);
        vt.push_back(make_pair(cost,make_pair(a,b)));
    }
    map<string,int>mp;
    for(string s:st){
        mp[s]=++cnt;
    }
    vector<pair<int,pair<int,int>>>v;
    for(auto it:vt){
        v.push_back(make_pair(it.first,make_pair(mp[it.second.first],mp[it.second.second])));
    }
    int m=(int)st.size();
    sort(v.begin(),v.end());
    int ans=0;
    DSU D(m+1);
    for(auto it:v){
        if(D.same(it.second.first,it.second.second))continue;
        ans+=it.first;
        D.unite(it.second.first,it.second.second);
    }
    if(D.get_size(v.front().second.second)!=m){
        cout<<"Case "<<test<<": "<<"Impossible"<<endl;
        return;
    }
    cout<<"Case "<<test<<": "<<ans<<endl;
}
int main(){
    int t;cin>>t;for(int i=1;i<=t;i++)sol(i);
}
