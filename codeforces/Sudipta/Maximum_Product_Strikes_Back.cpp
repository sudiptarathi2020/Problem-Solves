#include<bits/stdc++.h>
using namespace std;
void sol(){
    int n;cin>>n;
    vector<int>arr(n+1);
    vector<int>z;
    vector<int>t(n+1),neg(n+1);
    vector<int>leftmostneg(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==0){
            z.push_back(i);
        }
    }
    z.push_back(n+1);
    for(int i=1;i<=n;i++){
        t[i]+=t[i-1]+(arr[i]==2 or arr[i]==-2);
        neg[i]+=neg[i-1]+(arr[i]<0);
        leftmostneg[i]=arr[i]<0?i:leftmostneg[i-1];
    }
    int num=0;
    pair<int,int>a={n,0};
    for(int i=1;i<=n;i++){
        if(arr[i]==0)continue;
        int right=*lower_bound(z.begin(),z.end(),i)-1;
        if(neg[right]%2==neg[i-1]%2){
            if((t[right]-t[i-1])>num){
                a={i-1,n-right};
                num=t[right]-t[i-1];
            }
        }else{
            int leftminus=leftmostneg[right]-1;
            if(leftminus<i)continue;
            if((t[leftminus]-t[i-1])>num){
                num=t[leftminus]-t[i-1];
                a={i-1,n-leftminus};
            }
        }
    }
    cout<<a.first<<" "<<a.second<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
}
