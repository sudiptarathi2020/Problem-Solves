#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    if(n==1){
        cout<<"1\n";
        return 0;
    }
    if(n<=3){
        cout<<"NO SOLUTION\n";
        return 0;
    }else{
        if(n==4){
            cout<<"2 4 1 3\n";
            return 0;
        }
        vector<int>v;
        for(int i=1;i<=n;i+=2){
            v.push_back(i);
        }
        for(int i=2;i<=n;i+=2){
            v.push_back(i);
        }
        for(int I:v){
            cout<<I<<" ";
        }
    }
}
