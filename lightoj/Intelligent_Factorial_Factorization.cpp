
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    int casea=1;
    while(test--){
        int n;
        cin>>n;
        vector<pair<int,int>>v;
        bool arr[n+1];
        memset(arr,true,sizeof(arr));
        arr[0]=arr[1]=false;
        for(int i=2;i<=n;i++){
            if(arr[i]){
                int cnt=0;
                for(int j=i;j<=n;j+=i){
                    int k=j;
                    arr[j]=false;
                    while(k%i==0){
	                   cnt++;
                       k/=i;
                    }
                }
                v.push_back({i,cnt});
            }
        }
        cout<<"Case "<<casea<<": "<<n<<" = ";
        casea++;
        for(int i=0;i<(int)v.size();i++){
            cout<<v[i].first<<" ("<<v[i].second<<")";
            if(i!=(int)v.size()-1){
				cout<<" * ";
			}
        }
        cout<<'\n';
    }
}
