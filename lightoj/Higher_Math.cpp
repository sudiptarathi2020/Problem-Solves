
#include<iostream>
using namespace std;
int main()
{
    long long int temp,temp1,i,t_c,a,b,c;
    cin>>t_c;
    for(i=1;i<=t_c;i++)
    {
        cin>>a>>b>>c;
        if(a==0 || b==0 || c==0)
        {
            cout<<"Case "<<i<<": "<<"no"<<'\n';

        }
        else if(a*a+b*b==c*c || (a*a+c*c==b*b) || (b*b+c*c==a*a))
        {
            cout<<"Case "<<i<<": "<<"yes"<<'\n';
        }
        else
        {
            cout<<"Case "<<i<<": "<<"no"<<'\n';
        }
    }
    return 0;
}

