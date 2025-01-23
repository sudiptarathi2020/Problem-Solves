
#include<bits/stdc++.h>
using namespace std;
void sol(int test){
    int n;cin>>n;
    vector<vector<int>>arr(2*n,vector<int>(n));
    for(int i=0;i<2*n-1;i++){
        if(i>=n){
            for(int j=i-n+1;j<n;j++){
                cin>>arr[i][j];
            }
        }else{
            for(int j=0;j<=i;j++){
                cin>>arr[i][j];
            }
        }
    }
    for(int i=1;i<2*n;i++){
        for(int j=0;j<n;j++){
            if(j){
                arr[i][j]+=max(arr[i-1][j],arr[i-1][j-1]);
            }else{
                arr[i][j]+=arr[i-1][j];  
            }
        }
    }
    cout<<"Case "<<test<<": ";
    cout<<*max_element(arr[2*n-1].begin(),arr[2*n-1].end())<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;for(int i=1;i<=t;i++)sol(i);
}
