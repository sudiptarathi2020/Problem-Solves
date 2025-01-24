
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int test=1;test<=t;test++){
        int n,m;
        cin>>n>>m;
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        while(m--){
            char s;
            cin>>s;
            if(s=='S'){
                int a;cin>>a;
                for(int i=0;i<n;i++)arr[i]+=a;
            }
            else if(s=='R'){
                reverse(arr,arr+n);
            }
            else if(s=='P'){
                int a,b;cin>>a>>b;
                swap(arr[a],arr[b]);
            }
            else if(s=='D'){
                int a;cin>>a;
                for(int i=0;i<n;i++)arr[i]/=a;
            }else{
                int a;cin>>a;
                for(int i=0;i<n;i++)arr[i]*=a;
            }
        }
        cout<<"Case "<<test<<": \n";
        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        cout<<"\n";
    }
}
