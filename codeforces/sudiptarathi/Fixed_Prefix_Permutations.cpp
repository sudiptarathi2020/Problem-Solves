//https://codeforces.com/problemset/problem/1792/D
#include<bits/stdc++.h>
using namespace std;
void sol(){
    int n,m;cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    vector<vector<int>>brr(n,vector<int>(m));
    vector<vector<pair<int,int>>>arr(n,vector<pair<int,int>>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j].first;
            brr[i][j]=arr[i][j].first;
            arr[i][j].second=j+1;
        }
        sort(arr[i].begin(),arr[i].end());
        for(int j=0;j<m;j++){
            v[i][j]=arr[i][j].second;
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        vector<int>check(m,0);
        int ans=0;
        for(int j=0;j<m;j++){
            check[j]=brr[i][j];
            int k=0;
            auto it=lower_bound(v.begin(),v.end(),check);
            if(it==v.end()){
				break;
			}
            vector<int>ck=*it;
            for(;k<m;k++){
                if(brr[i][k]!=ck[k]){
                    break;
                }
            }
            ans=max(ans,k);
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}
int main(){
    int t;cin>>t;
    while(t--)sol();
}

