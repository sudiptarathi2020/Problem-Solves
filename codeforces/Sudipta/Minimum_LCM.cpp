#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N '\n'
#define S " "
void sol(){
    ll n;cin>>n;
    if(n&1 or 1){
        for(ll i=1;i*i<=n;i++){
            if(n%(i+1)==0){
                cout<<(n/(i+1))<<" "<<n-(n/(i+1))<<endl;
                return ;
            }
        }
    }
    cout<<n-1<<" "<<1<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    while(t--)sol();
    return 0;
}
