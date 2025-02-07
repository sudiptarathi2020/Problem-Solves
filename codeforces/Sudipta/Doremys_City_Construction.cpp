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
	set<ll>st;
	vector<ll>v(n);
	for(ll i=0;i<n;i++){
		cin>>v[i];
		st.insert(v[i]);
	}
	ll ans=0;
	sort(v.begin(),v.end());
	if((ll)st.size()==1){
		cout<<n/2<<endl;
		return ;
	}else{
		for(ll i=0;i<n;i++){
			if(i==0){
				if(v[i+1]==v[i]){
					continue;
				}else{
					ans=max(ans,n-1);
				}
			}else if(i==n-1){
				if(v[i]==v[i-1]){
					continue;
				}else{
					ans=max(ans,n-1);
				}
			}else{	
				if(v[i]==v[i+1]){
					continue;
				}else{
					//cout<<"jfk"<<" ";
					ll k=i+1;
					ll t=k*(n-1-k);
					//cout<<k<<" "<<t<<" sladkjf";
					ans=max(ans,k+t);
					//cout<<endl;
				}
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;cin>>t;
    while(t--)sol();
    return 0;
}
