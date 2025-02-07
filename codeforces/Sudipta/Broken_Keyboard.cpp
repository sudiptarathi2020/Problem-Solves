#include <bits/stdc++.h>
#define N '\n'
#define ll long long
#define L size()
using namespace std;
void solve()
{
    ll i,j,k,l;
    ll n;
    cin>>n;
    string s;
    ll cn=1;
    cin>>s;
    ll flag=0;
    for(i=0; i<s.L; i++)
    {
        if(cn%2==0)
        {
            if(i+1<s.L)
            {
                if(s[i]!=s[i+1])
                {
                    flag=1;
                }
            }
            else
            {
                flag=1;
            }
            i++;

        }
        cn++;
    }
    if(flag==1)
    {
        cout<<"NO"<<N;
    }
    else
    {
        cout<<"YES"<<N;
    }
    }
int main()
{
    ll test;
    cin>>test;
    while(test--)
    {
        solve();
    }
}
