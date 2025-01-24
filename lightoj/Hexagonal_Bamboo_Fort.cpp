
#include<bits/stdc++.h>
using namespace std;
const int N=300050;
int tree[N];
void add(int value){
    for(;value<N;value=value|(value+1)){
        tree[value]+=1;
    }
}
int get_range(int left,int right){
    left=max(left,0);
    int ret=0;
    for(;right>=0;right=(right&(right+1))-1){
        ret+=tree[right];
    }
    for(;left>=0;left=(left&(left+1))-1){
        ret-=tree[left];
    }
    return ret;
}
void solve(int test){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n && i>2;j++){
            for(int k=j+1;k<n;k++){
                int S=arr[k]-arr[j]-arr[i];
                ans+=get_range(S,N-1);
            }
        }
        for(int j=i-1;j>=0;j--){
            for(int k=j-1;k>=0;k--){
                int sum=arr[i]+arr[j]+arr[k];
                add(sum);
            }
        }
    }
    cout<<"Case "<<test<<": "<<ans<<endl;
}
int main(){
    int t;cin>>t;
    for(int i=1;i<=t;i++){
    memset(tree,0,sizeof tree);
        solve(i);
    }
}
