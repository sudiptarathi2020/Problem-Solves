#include<bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(),(x.end())
#define F first
#define S second
#define sz(x) (x).size()
const ll inf=1LL<<60;
const ll mod=1e9+7;
using pii=std::pair<int,int>;
using pll=std::pair<ll,ll>;
using vl=std::vector<ll>;
using vi=std::vector<int>;
using seti=std::set<int>;
using setl=std::set<ll>;
using namespace std;
void sol(int test_case);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
 
    int t=1;
   // cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}
struct seg{
    vector<int>tree;
    int N;
    seg(){}
    seg(int _N){
        this->N=_N;
        tree.resize(N<<2,0);
        build(1,0,N-1);
    }
    void build(int node,int start,int end){
        if(start==end){
            tree[node]=1;
        }else{
            int mid=(start+end)>>1;
            build(node<<1,start,mid);
            build(node<<1^1,mid+1,end);
            tree[node]=tree[node<<1]+tree[node<<1^1];
        }
    }
    void upd(int pos){
        int start=0,end=N-1,node=1;
        while(start!=end){
            tree[node]-=1;
            int mid=(start+end)>>1;
            if(pos<=mid){
                end=mid;
                node<<=1;
            }else{
                start=mid+1;
                node=node<<1^1;
            }
        }
        tree[node]-=1;
    }
    int get_number(int pos){
        int start=0,end=N-1,node=1;
        while(start!=end){
            if(pos==0)return start;
            int mid=(start+end)>>1;
            int sum=tree[node<<1];
            if(pos<=sum){
                end=mid;
                node<<=1;
            }else{
                start=mid+1;
                node=node<<1^1;
                pos-=sum;
            }
        }
        return start;
    }
};
void sol(int test_case){
    int n;cin>>n;
    seg s(n);
    vector<int>arr(n);
    for(auto &x:arr)cin>>x;
    while(n--){
        int a;cin>>a;
        int pos=s.get_number(a);
        cout<<arr[pos]<<" ";
        s.upd(pos);
    }
}
