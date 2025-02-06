#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
using namespace std;
struct dsu{
    vector<ll>parent;
    dsu(){

        parent.assign(26,0);
        iota(parent.begin(),parent.end(),0);
    }
    ll find(ll a){
        if(parent[a]==a){
            return a;
        }else{
            return parent[a]=find(parent[a]);
        }
    }
    void unify(ll a,ll b){
        a=find(a);
        b=find(b);
        if(a==b)return ;
        parent[a]=parent[b]=min(a,b);
    }

};
void sol(){
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    vector<ll>v;
    for(char ch:s){
        v.push_back(ch-'a');
    }
    dsu ds;
    ll cur_max=0;
    for(ll i=0;i<n;i++){
        if(v[i]<=cur_max){
            continue;
        }
        if(v[i]-cur_max>k){
            
            ll pt=v[i]-k;
            for(ll tk=pt;tk<=v[i];tk++){
                ds.unify(pt,tk);
            }
            k=0;
            break;
        }else if(v[i]<=cur_max){
            continue;
        }
        else{
           for(ll ii=cur_max;ii<=v[i];ii++){
               ds.unify((ll)cur_max,ii);
           }
           k-=v[i]-cur_max;
        }
        cur_max=max(cur_max,v[i]);
    }
    for(ll i=0;i<n;i++){
        cout<<(char)(ds.find(v[i])+'a')<<"";
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
