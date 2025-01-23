
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<ll,ll>;
using namespace std;
void sol(ll test){
    string s1,s2;cin>>s1>>s2;
    ll n1=s1.size(),n2=s2.size();
    ll M[n1+1][n2+1],Q[n1+1][n2+1];
    for(ll i=0;i<=n1;i++){
        M[i][0]=i;
        Q[i][0]=1;
    }
    for(ll i=0;i<=n2;i++){
        M[0][i]=i;
        Q[0][i]=1;
    }
    for(ll i=0;i<n1;i++){
        for(ll j=0;j<n2;j++){
            if(s1[i]==s2[j]){
                M[i+1][j+1]=M[i][j]+1;
                Q[i+1][j+1]=Q[i][j];
            }else{
                M[i+1][j+1]=1+min(M[i+1][j],M[i][j+1]);
                if(M[i][j+1]==M[i+1][j]){
                    Q[i+1][j+1]=Q[i][j+1]+Q[i+1][j];
                }else if(M[i][j+1]<M[i+1][j]){
                    Q[i+1][j+1]=Q[i][j+1];
                }else{
                    Q[i+1][j+1]=Q[i+1][j];
                }
            }
        }
    }
    cout<<"Case "<<test<<": "<<M[n1][n2]<<" "<<Q[n1][n2]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;
    cin>>t;
    for(ll i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}

