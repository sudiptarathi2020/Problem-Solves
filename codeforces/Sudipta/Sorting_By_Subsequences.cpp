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
    vector<vector<ll>>v;
    vector<pair<ll,ll>>arr(n);

    for(ll i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=i;
    }
    vector<ll>adj[n];
    sort(arr.begin(),arr.end());
    for(ll i=0;i<n;i++){
        adj[i].push_back(arr[i].second);
        adj[arr[i].second].push_back(i);

    }
    vector<bool>vis(n+1,false);
    for(ll i=0;i<n;i++){
        if(vis[i])continue;

        vector<ll>cc;
        queue<ll>q;
        q.push(i);
        while(q.size()){
            ll t=q.front();
            q.pop();
            if(vis[t])continue;
            vis[t]=true;
            cc.push_back(t);
            for(ll I:adj[t]){
                if(!vis[I]){
                    q.push(I);
                }
            }
        }
        v.push_back(cc);
    }
    cout<<(ll)v.size()<<endl;
    for(vector<ll>x:v){
        cout<<(ll)x.size()<<" ";
        sort(x.begin(),x.end());
        for(ll I:x){
            cout<<I+1<<" ";
        }
        cout<<endl;
    }


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;//cin>>t;
    while(t--)sol();
    return 0;
}
