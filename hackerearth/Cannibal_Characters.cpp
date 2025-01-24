#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--){
        map<char,int>mp;
        int n;string s;
        cin>>n>>s;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int ans=0;
        for(char c='a';c<='z';c++){
            if(mp[c]){
                ans+=(mp[c])/2;
            }
        }
        cout<<ans<<endl;
    }   
}
