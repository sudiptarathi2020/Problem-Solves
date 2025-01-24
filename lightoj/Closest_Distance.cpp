
#include<bits/stdc++.h>
#include <cmath>
#include <iomanip>
#include <ios>
#define ll long long
#define F first
#define S second
using pd=std::pair<long double,long double>;
using namespace std;
long double dist(pd a,pd b){
    return (a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S);
}
pd lc(pd a,pd b){
    pd ans;
    ans.F=(b.F+a.F*(long double)2)/(long double)3;
    ans.S=(b.S+a.S*(long double)2)/(long double)3;
    return ans;
}
pd rc(pd a,pd b){
  pd ans;
    ans.F=((long double)2*b.F+a.F)/(long double)3;
    ans.S=((long double)2*b.S+a.S)/(long double)3;
    return ans;
}
void sol(int test){
    pd a,b,c,d;
    cin>>a.F>>a.S>>b.F>>b.S>>c.F>>c.S>>d.F>>d.S;
    pd low=a,high=b;
    pd low1=c,high1=d;
    for(int i=0;i<100;i++){
        pd mid1=lc(low,high);
        pd mid2=rc(low,high);
        pd mid3=lc(low1,high1);
        pd mid4=rc(low1,high1);
        if(dist(mid1,mid3)<=dist(mid2,mid4)){
            high=mid2;
            high1=mid4;
        }else{
            low=mid1;
            low1=mid3;
        }
    }
    cout<<"Case "<<test<<": "<<fixed<<setprecision(8)<<sqrt(dist(low,low1))<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}

