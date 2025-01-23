
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define ull unsigned long long
#define all(x) (x).begin(),(x.end())
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define sz(x) (x).size()
const ll inf=1LL<<60;
const ll mod=1e9+7;
using pii=std::pair<int,int>;
using pll=std::pair<ll,ll>;
using vl=std::vector<ll>;
using vi=std::vector<int>;
using seti=std::set<int>;
using setl=std::set<ll>;
using pq=std::priority_queue<ll>;
using namespace std;
void sol(int test_case);
struct dsu{
    vector<int>par,sz;
    int n;
    int comp;
    dsu(){}
    dsu(int _n){
        n=_n;
        comp=n;
        par.resize(n);
        sz.resize(n,1);
        iota(all(par),0);
    }
    int find(int a){
        if(a==par[a])return a;
        return par[a]=find(par[a]);
    }
    void add(int a,int b){
        a=find(a),b=find(b);
        if(a==b)return;
        comp--;
        if(sz[a]<sz[b])swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
    }
    bool same(int a,int b){
        return find(a)==find(b);
    }
};
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
void sol(int test_case){
    int n;cin>>n;
    dsu d(n);
    int sum=0;
    vector<array<int,3>>edges;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a;cin>>a;
            if(a){
                edges.push_back({a,i,j});
                sum+=a;
            }
        }
    }
    sort(all(edges));
    int X=0;
    for(auto x:edges){
        if(d.same(x[1],x[2]))continue;
        d.add(x[1],x[2]);
        X+=x[0];
    }
    if(d.comp==1){
        cout<<"Case "<<test_case<<": "<<sum-X<<endl;
    }else{
        cout<<"Case "<<test_case<<": "<<-1<<endl;
    }
}

