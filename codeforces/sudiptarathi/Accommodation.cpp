//https://codeforces.com/problemset/problem/1804/D
#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,Mn,Mx;
int main(){
    cin>>n>>m;
    Mn=0,Mx=0;
    for(int ii=0;ii<n;ii++){
        cin>>s;
        int D2=0;
        int cnt1=count(s.begin(),s.end(),'1');
        for(int i=0;i+1<m;i++){
            if(s[i]=='1' and s[i+1]=='1'){
                D2++;
                i++;
            }
        }
        D2=min(m/4,D2);
        Mn+=cnt1-D2;
        D2=0;
        for(int i=0;i+1<m;i++){
            if(s[i]=='0' or s[i+1]=='0'){
                D2++;
                i++;
            }
        }
        D2=min(m/4,D2);
        Mx+=cnt1-(m/4-D2);
    }
    cout<<Mn<<" "<<Mx<<endl;
}
