#include<bits/stdc++.h>
#define ll long long 
using namespace std;
void sol(){
    ll n,k;cin>>n>>k;
    vector<vector<ll>>v(n+1,vector<ll>(n+1));
    for(ll i=0;i<n;i++){
        cin>>v[0][i];
    }
    vector<ll>comulative(n,0);
    for(ll i=1;i<=n;i++){
        set<ll,greater<ll>>st;
        for(ll j=0;j<n;j++){
            if((ll)st.size()<k){
                v[i][j]=v[0][j]-comulative[j];
                st.insert(v[i][j]);
            }else{
                v[i][j]=v[i][j-1];
            }

            comulative[j]+=v[i][j];
        }
        //cout<<"v[i][j]:    ";
       // for(ll I:v[i]){
         //   cout<<I<<" ";
        //}
        //cout<<endl;
        //cout<<"comulative: ";
        //for(ll I:comulative){
          //  cout<<I<<" ";
        //}
        //cout<<endl;
        bool t=true;
        
        for(ll j=0;j<n;j++){
            t&=(v[0][j]==comulative[j]);
        }
        if(t){
            cout<<i<<endl;return;
        }
        t=true;
        for(ll j=0;j<n;j++){
            t&=(v[i][j]==v[i-1][j]);
        }
        if(t){
            cout<<"-1\n";return;
        }
    }
    cout<<"-1\n";return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;cin>>t;
    while(t--)sol();
    return 0;
}
