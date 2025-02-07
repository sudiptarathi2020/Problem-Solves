#include <bits/stdc++.h>
#define N '\n'
#define ll long long
#define L size()
using namespace std;
void solve()
{
    ll i,j,k,l;
    ll n,a,b;
    cin>>n>>a>>b;
    if(a<=b)
    {
        if(n%a==0)
        {
            cout<<n/a<<N;
        }
        else
        {
            cout<<n/a+1<<N;
        }
    }
    else
    {
        cout<<1<<N;
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
