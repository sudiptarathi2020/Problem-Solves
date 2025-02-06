#include<bits/stdc++.h>
#define ll long long

using namespace std;
void sol(){
    ll n;cin>>n;
    map<char,ll>mp1;
    map<char,ll,greater<char>>mp2;
    mp1['a']=1;
    mp2['a']=1;
    for(ll i=0;i<n;i++){
        ll ch,b;cin>>ch>>b;
        string s;cin>>s;
        if(ch==1){
            for(char c:s){
                mp1[c]+=b;
            }
            bool t=false;
            map<char,ll>::iterator it1;
            map<char,ll,greater<char>>::iterator it2;
            for(it1=mp1.begin(),it2=mp2.begin();it1!=mp1.end() && it2!=mp2.end();it1++,it2++){
                if(it1->first<it2->first){
                    cout<<"YES\n";
                    t=true;
                    break;
                }else if(it1->first>it2->first){
                    cout<<"NO\n";
                    t=true;
                    break;
                }else{
                    if(it1->second==it2->second){
                        continue;
                    }else if(it1->second>it2->second){
                        auto it=mp2.end();it--;
                        if(it2==it){
                            t=true;
                            cout<<"NO\n";
                            break;
                        }else{
                            t=true;
                            cout<<"YES\n";
                            break;
                        }
                    }else if(it1->second<it2->second){
                        auto it=mp1.end();it--;
                        if(it1==it){
                            t=true;
                            cout<<"YES\n";
                            break;
                        }else{
                            t=true;
                            cout<<"NO\n";
                            break;
                        }
                    }
                }
            }

            if(!t){
                if(mp1.size()<mp2.size()){
                    cout<<"YES\n";
                }else{
                    cout<<"NO\n";
                }
            }

        }else{
            for(char c:s){
                mp2[c]+=b;
            }
            bool t=false;
            map<char,ll>::iterator it1;
            map<char,ll,greater<char>>::iterator it2;
            for(it1=mp1.begin(),it2=mp2.begin();it1!=mp1.end() && it2!=mp2.end();it1++,it2++){
                if(it1->first<it2->first){
                    cout<<"YES\n";
                    t=true;
                    break;
                }else if(it1->first>it2->first){
                    cout<<"NO\n";
                    t=true;
                    break;
                }else{
                    if(it1->second==it2->second){
                        continue;
                    }else if(it1->second>it2->second){
                        auto it=mp2.end();it--;
                        if(it2==it){
                            t=true;
                            cout<<"NO\n";
                            break;
                        }else{
                            t=true;
                            cout<<"YES\n";
                            break;
                        }
                    }else if(it1->second<it2->second){
                        auto it=mp1.end();it--;
                        if(it1==it){
                            t=true;
                            cout<<"YES\n";
                            break;
                        }else{
                            t=true;
                            cout<<"NO\n";
                            break;
                        }
                    }
                }
            }

            if(!t){
                if(mp1.size()<mp2.size()){
                    cout<<"YES\n";
                }else{
                    cout<<"NO\n";
                }
            }
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
