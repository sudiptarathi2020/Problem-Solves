
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string tos(int n){
    string s="";
    for(int i=0;i<32;i++){
        if(n&(1<<i)){
            s+="1";
        }else{
            s+="0";
        }
    }
    reverse(s.begin(),s.end());
    return s;
}
int sot(string s){
    int cnt=1;
    int ans=0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            ans+=cnt;
        }
        cnt*=2;
    }
    return ans;
}
void sol(){
    int n;cin>>n;
    string s=tos(n);
    next_permutation(s.begin(),s.end());
    cout<<sot(s)<<endl;
}
int main()
{
    ll t;cin>>t;
    int c=1;
    while(t--){
        cout<<"Case "<<c<<": ";
        sol();
        c++;
    }
    return 0;
}
