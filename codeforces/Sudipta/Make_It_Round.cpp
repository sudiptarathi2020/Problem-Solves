#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
using namespace std;
void sol(){
    ll n,k;
    cin>>n>>k;
    ll two=0,five=0;
    ll m=n;
    while(n%2==0 and n>0){
        two++;
        n/=2;
    }
    while(n%5==0 and n>0){
        five++;
        n/=5;
    }
    ll kt=1;
    while(two<five and kt*2<=k){
        two++;
        kt*=2;
    }
    while(five<two and kt*5<=k){
        five++;
        kt*=5;
    }
    while(kt*10<=k){
        kt*=10;
    }
    if(kt==1){
        cout<<m*k<<endl;
    }else{
        kt*=(k/kt);
        cout<<m*kt<<endl;
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
