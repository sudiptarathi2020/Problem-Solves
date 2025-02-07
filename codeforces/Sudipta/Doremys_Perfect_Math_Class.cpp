#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
using namespace std;  
void sol(){
	ll n;cin>>n;
	vector<ll>arr(n);
	ll mx=LLONG_MIN;
	for(ll i=0;i<n;i++){
		cin>>arr[i];
		mx=max(mx,arr[i]);
	}
	ll k=arr[0];
	for(ll i=1;i<n;i++){
		k=__gcd(k,arr[i]);
	}
	if(k==1){
		cout<<mx<<endl;
	}else{
		cout<<mx/k<<endl;
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;cin>>t;
    while(t--)sol();
    return 0;
}
