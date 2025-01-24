
#include<bits/stdc++.h>
using namespace std;
void sol(int test){
    int n,q;cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Case "<<test<<": \n";
    while(q--){
        int L,R;cin>>L>>R;
        if(R-L+1>1000){
            cout<<0<<endl;
        }else{
            vector<int>temp;
            for(int i=L;i<=R;i++){
                temp.push_back(arr[i]);
            }
            sort(temp.begin(),temp.end());
            int ans=1000;
            for(size_t i=1;i<temp.size();i++){
                ans=min(ans,temp[i]-temp[i-1]);
            }
            cout<<ans<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    for(int i=1;i<=t;i++)sol(i);
}
