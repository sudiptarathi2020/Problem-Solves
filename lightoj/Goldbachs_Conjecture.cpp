
#include<bits/stdc++.h>
using namespace std;
const int sz=1e7+100;
int main()
{
    bool arr[sz+10];
    memset(arr,true,sizeof(arr));
    arr[0]=arr[1]=false;
    for(int i=2;i*i<=sz;i++)
    {
        if(arr[i])
        {
            for(int j=i*i;j<=sz;j+=i)
            {
                arr[j]=false;
            }

        }
    }
    map<int,int>mp;
    vector<int>v;
    int k=0;
    for(int i=2;i<sz;i++)
    {
        if(arr[i])
        {
            v.push_back(i);
            mp[i]=k;
            k++;
        }
    }
    int test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        int n,i=0;
        cin>>n;
        auto it=mp.upper_bound(n);
        int l=(*it).second;
        //cout<<l<<'\n';
        int cnt=0;
        while(i<=l)
        {
           // cout<<"Entered\n";
            if(v[i]+v[l]==n)
            {
              //  cout<<"Equal\n";
                cnt++;
                i++;
            }
            else if(v[i]+v[l]<n)
            {
              //  cout<<"Less than\n";
                i++;
            }
            else
            {
               // cout<<"Greater than\n";
                l--;
            }
        }
        cout<<"Case "<<t<<": "<<cnt<<'\n';
    }
    return 0;

}








