
#include<bits/stdc++.h>
using namespace std;
struct node{
	int first;
	int second;
};
bool com(node a,node b){
	if(a.first<b.first){
		return true;
	}
	if(a.first==b.first){
		return a.second>b.second;
	}
	return false;
}
int main()
{
	int n=1001;
	node arr[n];
	arr[1].first=1;
	arr[1].second=1;
	for(int i=2;i<n;i++){
		int k=i;
		int ans=1;
		for(int j=2;j*j<=k;j++){
			int cnt=0;
			if(k%j==0){
				while(k%j==0){
					cnt++;
					k=k/j;
				}
				ans*=(cnt+1);
			}
		}
		if(k!=1){
			ans*=(2);
		}
		arr[i].first=ans;
		arr[i].second=i;
	}
	sort(arr+1,arr+n,com);
	int tt;
	cin>>tt;
	for(int ii=1;ii<=tt;ii++){
		int a;cin>>a;
		cout<<"Case "<<ii<<": "<<arr[a].second<<"\n";
	}
}
