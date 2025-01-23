
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
const long long mod=1e9+7;
long long binpow(long long a,long long b){
    long long ans=1;
    if(!b)return ans;
    while(b){
        if(b&1){
            ans*=a;
            ans%=mod;
        }
        a*=a;a%=mod;
        b>>=1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int test;cin>>test;
    while(test--){
        long long a,b;cin>>a>>b;
        cout<<binpow(a,b)<<endl;
    }
}
