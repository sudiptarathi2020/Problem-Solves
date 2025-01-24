
#include<iostream>
using namespace std;
int main()
{
    int k=0,n=0;
    int t_c,a,b;
    cin>>t_c;
    int i=1;
    for(;i<=t_c;i++)
    {
        n=0;
        cin>>a>>b;
        if(a>=b)
        {
            n=(a-b)*4;
        }
        else
        {
            n=(b-a)*4;
        }
       k=(a+2)*4;
        cout<<"Case "<<i<<": "<<n+k+11<<'\n';
    }
    return 0;
}
