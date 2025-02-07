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
	vector<ll>v(n);
	for(ll i=0;i<n;i++){
		cin>>v[i];
	}
	cout<<1<<" "<<n<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;cin>>t;
    while(t--)sol();
    return 0;
}
