
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int arr[10]={6,2,5,5,4,5,6,3,7,6};
    while(t--)
    {
        int rem,total=0;
        string a;
        cin>>a;
        int k=a.length();
        for(int i=0;i<k;i++)
        {
            int k=a[i]-'0';
            total=total+arr[k];
        }
        if(total%2==0)
        {
            for(int i=0;i<total/2;i++)
            {
                cout<<1;
            }
        }
        else
        {
            cout<<7;
            for(int i=1;i<total/2;i++)
            {
                cout<<1;
            }
        }
        cout<<'\n';
    }
    return 0;
}
