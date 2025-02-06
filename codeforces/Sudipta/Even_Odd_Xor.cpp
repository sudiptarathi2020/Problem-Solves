#include<bits/stdc++.h>
#define ll long long
using namespace std;
void sol(){
    ll n;cin>>n;
    if(n%4==0){
		vector<ll>ans(n,0);
		for(ll i=0;i<n/2;i++){
			ans[i]|=(1<<28);
		}
		ll cnt=1;
		for(ll i=0;i<n;i++){
			if(i==n/2)cnt=1;
			ans[i]|=cnt;
			cnt++;
		}
		for(ll I:ans){
		 cout<<I<<" ";
		}
		cout<<endl;
		return;
		
	}else if(n%4==1){
		n--;
		vector<ll>ans(n,0);
		for(ll i=0;i<n/2;i++){
			ans[i]|=(1<<28);
		}
		ll cnt=1;
		for(ll i=0;i<n;i++){
			if(i==n/2)cnt=1;
			ans[i]|=cnt;
			cnt++;
		}
		for(ll i=0;i<n;i++){
			ans[i]*=2;
			ans[i]|=1;
		}
		for(ll I:ans){
			cout<<I<<" ";
		}
		cout<<0;
		cout<<endl;
		return;
		
	}else if(n%4==2){
		ll k=n/2;
		vector<ll>ans1(k,0),ans2(k,0);
		ans1[0]|=(1<<29);
		ans1[k-1]|=(1<<28);
		for(ll i=1;i<k-1;i++){
			ans2[i]|=(1<<29);
			ans2[i]|=(1<<28);
		}
		ll cnt=1;
		for(ll i=0;i<k;i++){
			ans1[i]|=cnt;
			ans2[i]|=cnt;
			cnt++;
		}
		
		for(ll i=0;i<k;i++){
			//kt^=ans1[i];
			//kt1^=ans2[i];
			cout<<ans1[i]<<" "<<ans2[i]<<" ";
		}
		//cout<<kt<<" "<<kt1<<endl;
		cout<<endl;
		return;
	}else{
		n-=3;
		vector<ll>ans(n,0);
		for(ll i=0;i<n/2;i++){
			ans[i]|=(1<<28);
		}
		ll cnt=1;
		for(ll i=0;i<n;i++){
			if(i==n/2)cnt=1;
			ans[i]|=cnt;
			cnt++;
		}
		//~ for(ll I:ans){
			//~ cout<<I<<" ";
		//~ }
		for(ll i=0;i<n;i++){
			ans[i]*=2;
			ans[i]|=1;
		}
		for(ll i=0;i<n;i++){
			cout<<(2*ans[i]|1)<<" ";
		}
		cout<<"2 1 3"<<endl;
		return;
		
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
