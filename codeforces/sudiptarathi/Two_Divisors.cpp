//https://codeforces.com/problemset/problem/1366/D
#include<bits/stdc++.h>
#include <utility>
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

    int t=1;//cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}
const int N=1e7+10;
int arr[N+1];
pair<int,int> get_div(int a){
    if(a==2)return make_pair(-1,-1);
    vector<int>xx;
    while(a!=1){
        int p=arr[a];
        xx.push_back(p);
        while(a%p==0){
            a/=p;
        }
    }
    if(xx.size()==1){
        return make_pair(-1,-1);
    }
    if(xx.size()==2){
        return make_pair(xx[0],xx[1]);
    }
    for(int i=1;i<(int)xx.size();i++){
        xx[i]*=xx[i-1];
    }
    int mid=(0+xx.size())/2;
    return make_pair(xx[mid],xx.back()/xx[mid]);
}
void sol(int test_case){
    iota(arr,arr+N,0);
    for(int i=2;i*i<=N;i++){
        if(i==arr[i]){
            for(int j=i*i;j<=N;j+=i){
                arr[j]=min(arr[j],i);
            }
        }
    }
    int n;cin>>n;
    int brr[n];
    pair<int,int> ans[n];
    for(int i=0;i<n;i++){
        cin>>brr[i];
        ans[i]=get_div(brr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i].first<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i].second<<" ";
    }
}

