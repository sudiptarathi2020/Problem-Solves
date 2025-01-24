#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int q,n;
        cin>>n>>q;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n);
        cout<<"Case "<<i<<": \n";
        while(q--){
            int a,b;
            cin>>a>>b;
            int u=upper_bound(arr,arr+n,b)-arr;
            int l=lower_bound(arr,arr+n,a)-arr;
            cout<<u-l<<endl;
        }




    }
}
