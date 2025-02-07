#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
using namespace std;
void sol(){
    set<pair<ll,ll>,greater<pair<ll,ll>>>st,pt;
    ll n,k;cin>>n>>k;
    vector<pair<ll,ll>>v(n);
    vector<pair<ll,ll>>ans(n);
    for(ll i=0;i<n;i++){
        cin>>v[i].first;
        ans[i].first=v[i].first;
    }
    for(ll i=0;i<n;i++){
        cin>>v[i].second;
        ans[i].second=v[i].second;
    } 
    map<ll,ll>mp;
    sort(v.begin(),v.end());
    for(ll i=0;i<n;i++){
    //    st.insert(make_pair(v[i].first,v[i].second));
        pt.insert(make_pair(v[i].second,v[i].first));
    }
    for(ll i=(ll)v.size()-1;i>=0;i--){
        ll t=v[i].first;
        ll kt=v[i].second;
        pt.erase(pt.find(make_pair(v[i].second,v[i].first)));
        ll cnt=k;
        for(auto I:pt){
            if(cnt==0){
                break;
            }
            kt+=I.first;
            cnt--;
        }
        mp[t]=kt;
    }
    for(auto I:ans){
        cout<<mp[I.first]<<" ";
    }
    cout<<endl;


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;//cin>>t;
    while(t--)sol();
    return 0;
}
