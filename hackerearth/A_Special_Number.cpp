#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        while(1)
        {
            int t=0;
            int b=a;
            while(b)
            {
                t+=b%10;
                b/=10;
            }
            if(t%4==0)
            {
                cout<<a<<'\n';
                break;
            }
            a++;
        }
    }
    return 0;
}
