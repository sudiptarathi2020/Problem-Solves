//https://codeforces.com/problemset/problem/1468/F
#include<bits/stdc++.h>
#define ll long long
#define mkp make_pair
using namespace std;
void sol(){
    ll n,a,b,c,d;cin>>n;
    map<pair<ll,ll>,ll>mp;
    map<pair<ll,ll>,bool>vis;
    for(ll i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        a-=c,b-=d;
        ll _g=__gcd(abs(a),abs(b));
        mp[mkp(a/_g,b/_g)]++;
    }
    ll ans=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        ll f=it->first.first;
        ll s=it->first.second;
        if(vis[mkp(f,s)])continue;
        ll M=it->second;
        ll ff=(-1)*f;
        ll ss=(-1)*s;
        ll MM=mp[mkp(ff,ss)];
        ans+=M*MM;
        vis[mkp(f,s)]=true;
        vis[mkp(ff,ss)]=true;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    ll t;cin>>t;while(t--)sol();
    return 0;
}
