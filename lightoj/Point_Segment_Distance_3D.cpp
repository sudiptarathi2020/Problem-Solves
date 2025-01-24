
#include<bits/stdc++.h>
#define ll long long
#define F first.first
#define S first.second
#define T second
using pd=std::pair<std::pair<long double,long double>,long double>;
using namespace std;
long double dist(pd a,pd b){
    return (a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S)+(a.T-b.T)*(a.T-b.T);
}
pd lc(pd a,pd b){
    pd ans;
    ans.F=(b.F+a.F*(long double)2)/(long double)3;
    ans.S=(b.S+a.S*(long double)2)/(long double)3;
    ans.T=(b.T+a.T*(long double)2)/(long double)3;
    return ans;
}
pd rc(pd a,pd b){
    pd ans;
    ans.F=((long double)2*b.F+a.F)/(long double)3;
    ans.S=((long double)2*b.S+a.S)/(long double)3;
    ans.T=((long double)2*b.T+a.T)/(long double)3;
    return ans;
}
void sol(int test){
    pd a,b;
    cin>>a.F>>a.S>>a.T>>b.F>>b.S>>b.T;
    pd p;cin>>p.F>>p.S>>p.T;
    pd low=a,high=b;
    pd ans;
    for(int i=0;i<100;i++){
        pd mid1=lc(low,high);
        pd mid2=rc(low,high);
        if(dist(p,mid1)<=dist(p,mid2)){
            high=mid2;
            ans=mid1;
        }else{
            low=mid1;
            ans=mid2;
        }
    }
    cout<<"Case "<<test<<": "<<fixed<<setprecision(8)<<sqrt(dist(ans,p))<<endl;
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

