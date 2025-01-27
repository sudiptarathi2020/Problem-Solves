#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define mkp make_pair
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
#define IN cin
#define out cout
#define elif else if
#define yes cout<<"yes\n";
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define no cout<<"no\n";
#define fst first
#define scnd second
#define all(s) (s).begin(),(s.end())
#define sz(x) (ll)(x).size();
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define FORd(i,a,b) for(int i=a;i>=b;i--)
#define F0Rd(i,a) for(int i=a;i>=0;i--)
using namespace std;
const ll inf=LLONG_MAX;
const ll ninf=LLONG_MIN;
const ll N=2e5;
const ll mod=1e9+7;
typedef pair<ll,ll> pl;
typedef set<ll> st;
typedef queue<ll> ql;
typedef queue<pl> qpl;
typedef stack<ll> stk;
typedef stack<pl> stkp;
typedef priority_queue<ll> pq;
typedef priority_queue<ll,vector<ll>,greater<ll>> rpq;
typedef priority_queue<pl> pql;
typedef priority_queue<pl,vector<pl>,greater<pl>> rpql;
typedef set<pl> stp;
typedef vector<ll> vl;
typedef set<ll,greater<ll>> rst;
typedef set<pl,greater<pl>> rstp;
typedef vector<pl> vpl;
typedef vector<string> vs;
struct dsu{
    int n;
    vector<int>parent,Sz;
    dsu(){}
    dsu(int nn){
        this->n=nn;
        parent.resize(n+1);
        Sz.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            Sz[i]=1;
        }
    }
    int find(int a){
        if(parent[a]==a){
            return parent[a];
        }else{
            return parent[a]=find(parent[a]);
        }
    }
    void unify(int a,int b){
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
    bool isconnected(int a,int b){
        return find(a)==find(b);
    }
};
void sol(ll test){
    int n;cin>>n;
    bool arr[n+1][n+1];
    memset(arr,false,sizeof(arr));
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        arr[a-1][b-1]=true;
    }
    vector<pair<int,pair<int,int>>>v;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i][j]){
                v.push_back(make_pair(1,make_pair(i,j)));
            }else{
                v.push_back(make_pair(2,make_pair(i,j)));
            }
        }
    }
    sort(all(v));
    dsu d(n+1);
    vector<pair<int,int>>ans1,ans2;
    for(auto x:v){
        if(d.isconnected(x.second.first,x.second.second)){
            if(x.first==1){
                ans1.push_back(mkp(x.second.first,x.second.second));
            }

        }else{
            d.unify(x.second.first,x.second.second);
            if(x.first==2){
                ans2.push_back(mkp(x.second.first,x.second.second));
            }
        }
    }
    assert(ans2.size()==ans1.size());
    cout<<(int)ans1.size()<<endl;
    for(int i=0;i<(int)ans1.size();i++){
        cout<<ans1[i].first+1<<" "<<ans1[i].second+1<<" "<<ans2[i].first+1<<" "<<ans2[i].second+1<<endl;
    }
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;//cin>>t;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}
 