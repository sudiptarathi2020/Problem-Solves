#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
using namespace std;
void sol(){
    ll n;cin>>n;
    
    if(n&1){
        vector<ll>v;
        v.pb(n*4);
        ll k=n*4-1,kk=n*4+1;
        for(int i=1;i<n/2;i++){
            v.pb(k);k--;
            v.pb(kk);kk++;
        }
        v.pb((4*(2*n-1)+4+2*n)/2);
        v.pb(4*(2*n-1)+4-v.back());
        sort(v.begin(),v.end());
        ll sum=0;
        for(int I:v){
            cout<<I<<" ";
            sum+=I;
        }
        assert(*max_element(v.begin(),v.end())-*min_element(v.begin(),v.end())==sqrt(sum));
        cout<<endl;
    }else{
        vector<ll>v;
        ll k=4*n+1,kk=4*n-1;
        for(int i=1;i<n/2;i++){
            v.pb(k);k++;
            v.pb(kk);kk--;
        }
        v.pb((4*(2*n-1)+4+2*n)/2);

        v.pb(4*(2*n-1)+4-v.back());
        sort(v.begin(),v.end());
        ll sum=0;
        for(int I:v){
            cout<<I<<" ";
            sum+=I;
        }
        assert(*max_element(v.begin(),v.end())-*min_element(v.begin(),v.end())==sqrt(sum));

        cout<<endl;
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
