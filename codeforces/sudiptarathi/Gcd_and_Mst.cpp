//https://codeforces.com/problemset/problem/1513/D
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int par[N];
int rnk[N];
int find(int x){
    if(x==par[x])return par[x];
    return par[x]=find(par[x]);
}
void add(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return;
    if(rnk[a]<rnk[b])swap(a,b);
    par[b]=a;
    if(rnk[a]==rnk[b])rnk[b]++;
}
bool same(int a,int b){
    return find(a)==find(b);
}
void solve(){
    iota(par,par+N,0);
    memset(rnk,1,sizeof rnk);
    int n,m;cin>>n>>m;
    pair<int,int> arr[n];
    int brr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        brr[i]=arr[i].first;
        arr[i].second=i;
    }
    long long ans=0;
    sort(arr,arr+n);
    for(pair<int,int>x:arr){
        int best=x.first;
        int index=x.second;
        if(best>=m)break;
        while(index>0){
            if(brr[index-1]%best==0 and same(x.second,index-1)==false){
                ans+=(long long)best;
                add(x.second,index-1);
                index--;
            }else{
                break;
            }
        }
        index=x.second;
        while(index<n-1){
            if(brr[index+1]%best==0 and same(x.second,index+1)==false){
                ans+=(long long)best;
                add(x.second,index+1);
                index++;
            }else{
                break;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        if(same(i,i+1)==false)ans+=(long long)m;
    }
    cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;while(t--)solve();
}
