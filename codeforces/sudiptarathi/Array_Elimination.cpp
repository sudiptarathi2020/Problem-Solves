//https://codeforces.com/problemset/problem/1601/A
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
#define endl '\n'
using namespace std;
const int N=200100;
int sieve[N];
void sol(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int g=0,k=0;
    for(int i=0;i<31;i++){
        for(int j=0;j<n;j++){
            k+=(arr[j]&(1<<i))?1:0;
        }
        g=gcd(g,k),k=0;
    }
    vector<int>ans;
    for(int i=1;i<=g;i++){
        if(g%i==0){
            ans.push_back(i);
        }
    }
    if(ans.size()==0){
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;while(t--)sol();
}

