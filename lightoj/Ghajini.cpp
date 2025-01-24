
#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5+1;
const int maxLog = 20;
int stMax[maxN][maxLog];
int stMin[maxN][maxLog];
int lg[maxN];
void init(int arr[],int n){
    for(int i=0;i<n;i++){
        stMax[i][0] = arr[i];
        stMin[i][0] = arr[i];
    }
    for(int j=1;j<maxLog;j++){
        for(int i=0;i+(1<<j)<=n;i++){
            stMax[i][j] = max(stMax[i][j-1],stMax[i+(1<<(j-1))][j-1]);
            stMin[i][j] = min(stMin[i][j-1],stMin[i+(1<<(j-1))][j-1]);
        }
    }
}
int queryMax(int l,int r){
    if(l<0)l=0;
    int j = lg[r-l+1];
    return max(stMax[l][j],stMax[r-(1<<j)+1][j]);
}
int queryMin(int l,int r){
    if(l<0)l=0;
    int j = lg[r-l+1];
    return min(stMin[l][j],stMin[r-(1<<j)+1][j]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    lg[1] = 0;
    for(int i=2;i<maxN;i++){
        lg[i] = lg[i/2]+1;
    }
    int tcs;
    cin>>tcs;
    for(int tc=1;tc<=tcs;tc++){
        int n,d;
        cin>>n>>d;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        init(arr,n);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, queryMax(i-d+1,i)-queryMin(i-d+1,i));
        }
        cout<<"Case "<<tc<<": "<<ans<<endl;
    }
}
