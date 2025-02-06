#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N=2e5+10;
int arr[N];
ll ok(ll po,ll ind,ll db,ll tr,ll n){
    if(ind==n){
        return 0;
    }
    if(po>arr[ind]){
        return 1+ok(po+arr[ind]/2,ind+1,db,tr,n); 
    }else{
        ll M1=0,M2=0;
        if(db){
            M1= ok(po*2,ind,db-1,tr,n);
        }
        if(tr){
            M2= ok(po*3,ind,db,tr-1,n);
        }
        return max(M1,M2);
    }
   
}
void sol(){
     ll n,k;cin>>n>>k;
     for(ll i=0;i<n;i++){
         cin>>arr[i];
     }
     sort(arr,arr+n);
     cout<<ok(k,0,2,1,n)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;cin>>t;
    while(t--)sol();
    return 0;
}
