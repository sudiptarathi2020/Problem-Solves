#include<bits/stdc++.h>
using namespace std;
int main()
{
    bool f=false;
    string a;
    cin>>a;
    for(int i=0;i<8;i++)
    {
        if(i==1 ||i==5)
        {
            i++;
        }
        else
        {
            int b=a[i]-'0';
            int c=a[i+1]-'0';
            if((b+c)%2)
            {
                f=true;
                break;
            }
        }
        if(a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'||a[i]=='Y')
        {
            f=true;
            break;
        }
    }
    if(f)
    {
        cout<<"invalid\n";
    }
    else
    {
        cout<<"valid\n";
    }
    return 0;
}
