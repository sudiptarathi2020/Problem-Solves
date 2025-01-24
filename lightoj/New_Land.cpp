
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
int get_max_area_in_histogram(int a[],int n){
    stack<int>stk;
    int index=0,max_area=0;;
    while(index<n){
        if(stk.empty() or a[index]>=a[stk.top()]){
            stk.push(index);
            index++;
        }else{
            int tp=stk.top();
            stk.pop();
            if(stk.empty()){
                int area=a[tp]*index;
                max_area=max(max_area,area);
            }else{
                int area=a[tp]*(index-stk.top()-1);
                max_area=max(max_area,area);
            }
        }
    }
    while(stk.size()){
        int tp=stk.top();
        stk.pop();
        if(stk.empty()){
            int area=a[tp]*index;
            max_area=max(max_area,area);
        }else{
            int area=a[tp]*(index-stk.top()-1);
            max_area=max(max_area,area);
        }
    }
    return max_area;
}
void sol(int test){
    int n,m;cin>>n>>m;
    int ans=0;
    int a[m];memset(a,0,sizeof(a));
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int i=0;i<m;i++){
            if(s[i]=='0'){
                a[i]+=1;
            }else{
                a[i]=0;
            }
        }
        ans=max(ans,get_max_area_in_histogram(a,m));
    }
    cout<<"Case "<<test<<": "<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    for(int i=1;i<=t;i++)sol(i);
}
