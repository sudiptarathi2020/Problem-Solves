#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
using namespace std;
void sol(){
    ll n;cin>>n;
    ll odd=0,even=0;
    for(ll i=0;i<n;i++){
        ll a;cin>>a;
        if(a&1){
            odd++;
        }
    }
    even=n-odd;
    if(odd%4==0 or odd%4==3){
        cout<<"Alice\n";
    }else if(odd%4==2){
        cout<<"Bob\n";
    }else{
        if(even%2==0){
            cout<<"Bob\n";
        }else{
            cout<<"Alice\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
