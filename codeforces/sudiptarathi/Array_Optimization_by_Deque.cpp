//https://codeforces.com/problemset/problem/1579/E2
#include <ext/pb_ds/assoc_container.hpp>
#include <functional> 
#include<bits/stdc++.h>
#define ll long long
using namespace __gnu_pbds;
using namespace std;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,
			tree_order_statistics_node_update>
	ordered_multiset;

void sol()
{
	ordered_multiset p;
    ll n;cin>>n;
    ll arr[n];
    list<ll>lst;
    map<ll,ll>mp;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(p.size()==0){
            p.insert(arr[i]);
            lst.push_back(arr[i]);
        }else{
            ll I=p.order_of_key(arr[i]);
            ll II=p.order_of_key(arr[i]+1);
            II=p.size()-II;
            if(I<II){
                lst.push_front(arr[i]);
            }else{
                lst.push_back(arr[i]);
            }
            p.insert(arr[i]);
        }
    }
    p.clear();    
    vector<ll>v;
    for(ll i:lst){
        v.push_back(i);
    }
    ll ans=0;
    for(ll i=v.size()-1;i>=0;i--){
        ll K=v[i];
        ans+=p.order_of_key(K);
        p.insert(K);
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    ll t;cin>>t;while(t--)sol();
}

