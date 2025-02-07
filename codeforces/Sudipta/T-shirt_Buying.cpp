#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
using namespace std;
        
void sol(){
    ll n;cin>>n;
    vector<array<ll,3>>v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i][0];
    }
    for(ll i=0;i<n;i++){
        cin>>v[i][1];
    }
    for(ll i=0;i<n;i++){
        cin>>v[i][2];
    }
    set<ll>st1,st2,st3;
    for(ll i=0;i<n;i++){
        if(v[i][1]==1){
            st1.insert(v[i][0]);
        }else if(v[i][1]==2){
            st2.insert(v[i][0]);
        }else{
            st3.insert(v[i][0]);
        }
        if(v[i][2]==1){
            st1.insert(v[i][0]);
        }else if(v[i][2]==2){
            st2.insert(v[i][0]);
        }else{
            st3.insert(v[i][0]);
        }
    }
    ll mem;cin>>mem;

    for(ll i=1;i<=mem;i++){
        ll a;cin>>a;
        if(a==1){
            if(st1.size()==0){
                cout<<"-1 ";
                continue;
            }else{
                ll k=*st1.begin();
                cout<<k<<" ";
                st1.erase(st1.begin());
                if(st2.count(k)){
                    st2.erase(st2.find(k));
                }
                if(st3.count(k)){
                    st3.erase(st3.find(k));
                }
            }
        }else if(a==2){
            if(st2.size()==0){
                cout<<-1<<" ";continue;

            }else{
                ll k=*st2.begin();
                cout<<k<<" ";
                st2.erase(st2.begin());
                if(st1.count(k)){
                    st1.erase(st1.find(k));
                }
                if(st3.count(k)){
                    st3.erase(st3.find(k));
                }
            }
        }else{
            if(st3.size()==0){
                cout<<"-1 ";
            }else{
                ll k=*st3.begin();
                cout<<k<<" ";
                st3.erase(st3.begin());
                if(st1.count(k)){
                    st1.erase(st1.find(k));
                }
                if(st2.count(k)){
                    st2.erase(st2.find(k));
                }
            }
        }
    }





}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;//cin>>t;
    while(t--)sol();
    return 0;
}
