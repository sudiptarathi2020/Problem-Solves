#include<bits/stdc++.h>
using namespace std;
const int N=1e5+500;
vector<bool>prms(N+1,true);
vector<int>v;
void sol(){
    int n;cin>>n;
    vector<int>check;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        for(int j=0;v[j]*v[j]<=a;j++){
            if(a%v[j]==0){
                check.push_back(v[j]);
                while(a%v[j]==0){
                    a/=v[j];
                }
            }
        }
        if(a>1){
            check.push_back(a);
        }
    }
    sort(check.begin(),check.end());
    for(int i=0;i<(int)check.size()-1;i++){
        if(check[i]==check[i+1]){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main(){
    prms[0]=prms[1]=false;
    for(int i=2;i*i<=N;i++){
        if(prms[i]){
            for(int j=i*i;j<=N;j+=i){
                prms[j]=false;
            }
        }
    }
    for(int i=2;i<=N;i++){
        if(prms[i]){
            v.push_back(i);
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
