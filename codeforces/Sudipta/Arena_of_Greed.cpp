#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
using namespace std;
        
void sol(){
    ll cnt=0;
    ll n;cin>>n;
    ll ans1=0,ans2=0;
    while(n>0){
        if(n&1){
            if(cnt%2==0){
                ans1+=1;
                n--;
            }else{
                ans2+=1;
                n--;
            }
        }else{
            if(cnt%2==0){
                if(n%4==0 and n>4){
                    ans1+=1;
                    n--;
                }else{
                    ans1+=n/2;
                    n/=2;
                }
            }else{
                if(n%4==0 and n>4){
                    ans2+=1;
                    n--;
                }else{
                    ans2+=n/2;
                    n/=2;
                }
            }   
        }
        cnt++;
    }
    cout<<ans1<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;cin>>t;
    while(t--)sol();
    return 0;
}
