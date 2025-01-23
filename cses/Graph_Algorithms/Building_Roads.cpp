#include<bits/stdc++.h>
using namespace std;
struct dsu{
    vector<int>PAR;
    vector<int>SZ;
    dsu(){}
    dsu(int N){
        PAR.resize(N+1);
        iota(PAR.begin(),PAR.end(),0);
        SZ.resize(N+1,1);
    }
    int find(int a){
        if(a==PAR[a])return PAR[a];
        return PAR[a]=find(PAR[a]);
    }
    void add(int a,int b){
        a=find(a),b=find(b);
        if(a==b)return;
        if(SZ[a]<SZ[b])swap(a,b);
        PAR[b]=a;SZ[a]+=SZ[b];
    }
};
int main(){
    int a,b,n,m;cin>>n>>m;
    dsu D(n);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        D.add(a,b);
    }
    set<int>ST;
    for(int i=1;i<=n;i++){
        ST.insert(D.find(i));
    }
    vector<int>arr;
    for(auto x:ST)arr.push_back(x);
    cout<<arr.size()-1<<endl;
    for(int i=0;i<(int)arr.size()-1;i++){
        cout<<arr[i]<<" "<<arr[i+1]<<endl;
    }
}
