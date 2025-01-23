
#include <bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
const int inf=1e9;
const int mod=1e9+7;
void sol(int test){
    int x,n,w,k;cin>>n>>w>>k;
    vector<int>a(n+1,(-1)*inf),front_a(n+1),back_a_nile_baki_thake(n+1),dp(n+1,0),mx(n+1,0);
    for(int i=0;i<n;i++){
        cin>>x>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++){
        int X=upper_bound(a.begin(),a.end(),a[i]+w)-a.begin();
        front_a[i]=X-i;
    }
    for(int i=1;i<=n;i++){
        int X=lower_bound(a.begin(),a.end(),a[i]-w)-a.begin();
        back_a_nile_baki_thake[i]=X-1;
    }
    for(int i=0;i<k;i++){
        for(int j=1;j<=n;j++){
            dp[j]=front_a[j]+mx[back_a_nile_baki_thake[j]];
        }
        for(int j=1;j<=n;j++){
            mx[j]=max(mx[j-1],dp[j]);
        }
    }
    cout<<"Case "<<test<<": "<<*max_element(dp.begin(),dp.end())<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
}

