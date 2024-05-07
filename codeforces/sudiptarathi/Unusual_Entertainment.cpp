//https://codeforces.com/problemset/problem/1899/G
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
struct seg{
    int n;
    vector<vector<int>>tree;
    seg(){}
    seg(int _n){
        n=_n;
        tree.resize(n<<2);
    }
    void build(int node,int start,int end,vector<int>&arr){
        if(start==end){
            tree[node]=vector<int>(1,arr[start]);
            return;
        }else{
            int mid=(start+end)>>1;
            build(node<<1,start,mid,arr);
            build(node<<1|1,mid+1,end,arr);
            long unsigned int Left=0,Right=0;
            while(Left<tree[node<<1].size() and Right<tree[node<<1|1].size()){
                if(tree[node<<1][Left]<=tree[node<<1|1][Right]){
                    tree[node].pb(tree[node<<1][Left]);
                    Left++;
                }else{
                    tree[node].pb(tree[node<<1|1][Right]);
                    Right++;
                }
            }
            while(Left<tree[node<<1].size()){
                tree[node].pb(tree[node<<1][Left]);
                Left++;
            }
            while(Right<tree[node<<1|1].size()){
                tree[node].pb(tree[node<<1|1][Right]);
                Right++;
            }
        }
    }
    void build(vector<int>&arr){
        build(1,0,n-1,arr);
    }
    bool contains(int node,int start,int end,int left,int right,int mn,int mx){
        if(start==left and end==right){
            int P=lower_bound(all(tree[node]),mx)-tree[node].begin();
            int Q=lower_bound(all(tree[node]),mn)-tree[node].begin();
            if(P-Q>0)return true;
            return false;
        }
        int mid=(start+end)>>1;
        if(right<=mid){
            return contains(node<<1,start,mid,left,right,mn,mx);
        }else if(mid<left){
            return contains(node<<1|1,mid+1,end,left,right,mn,mx);
        }else{
            bool first=contains(node<<1,start,mid,left,mid,mn,mx);
            if(first)return true;
            bool second=contains(node<<1|1,mid+1,end,mid+1,right,mn,mx);
            return first||second;
        }
    }
};
vector<vector<int>>edges;
vector<int>in,out;
int timer=0;
void dfs(int source,int parent){
    in[source]=timer;timer++;
    for(int x:edges[source]){
        if(x==parent)continue;
        dfs(x,source);
    }
    out[source]=timer;timer++;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//freopen("in.txt","r",stdin);
	int t;cin>>t;
	while(t--)sol(t);
}
void sol(int test_case){
    timer=0;
    edges.clear(),in.clear(),out.clear();
    int n,q;cin>>n>>q;
    edges.resize(n),in.resize(n),out.resize(n);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b,a--,b--;
        edges[a].pb(b),edges[b].pb(a);
    }
    dfs(0,0);
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]=in[arr[i]-1];
    }
    seg S(n);
    S.build(arr);
    while(q--){
        int a,b,c;cin>>a>>b>>c,a--,b--,c--;
        if(S.contains(1,0,n-1,a,b,in[c],out[c])){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
    }
}

