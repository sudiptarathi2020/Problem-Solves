
#include<bits/stdc++.h>
using namespace std;
struct dsu{
    int n;
    vector<int>parent,Sz;
    dsu(){}
    dsu(int _n){
        this->n=_n+1;
        parent.resize(n+1);
        iota(parent.begin(),parent.end(),0);
        Sz.assign(n+1,1);
    }
    int find(int a){
        if(parent[a]==a){
            return a;
        }
        return parent[a]=find(parent[a]);
    }
    void Unify(int a,int b){
        a=find(a),b=find(b);
        if(a==b){
            return;
        }
        if(Sz[a]<Sz[b]){
            swap(a,b);
        }
        parent[b]=a;
        Sz[a]+=Sz[b];
    }
    bool same(int a,int b){
        return find(a)==find(b);
    }
};
void sol(int test){
    int a,b,c,n;cin>>n;
    dsu D(n),DD(n);
    vector<array<int,3>>v;
    for(;;){
        cin>>a>>b>>c;
        if(a==0 and b==0 and c==0){
            break;
        }
        v.push_back({c,a,b});
    }
    sort(v.begin(),v.end());
    int ans1=0,ans2=0;
    for(auto x:v){
        if(D.same(x[1],x[2]))continue;
        ans1+=x[0];
        D.Unify(x[1],x[2]);
    }
    sort(v.rbegin(),v.rend());
    for(auto x:v){
        if(DD.same(x[1],x[2]))continue;
        ans2+=x[0];
        DD.Unify(x[1],x[2]);
    }
    cout<<"Case "<<test<<": ";
    if((ans1+ans2)%2==0){
        cout<<(ans1+ans2)/2<<endl;
    }else{
        cout<<(ans1+ans2)<<"/"<<2<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}
