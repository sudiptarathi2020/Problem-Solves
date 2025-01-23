
#include<bits/stdc++.h>
#include <unordered_map>
#define ll long long
using namespace std;
struct node{
    ll pos,val,left,right;
    node(){}
};
bool opt(node a,node b){
    if(a.val>b.val){return true;}
    else if(a.val<b.val){return false;}
    else{return a.left>b.left;}
}
struct BIT{
    vector<ll>tree;
    ll n;
    BIT(){}
    BIT(ll _n){
        this->n=_n;
        tree.resize(n,0);
    }
    void add(ll index,ll val){
        for(;index<n;index=index|(index+1)){
            tree[index]+=val;
        }
    }
    ll sum(ll l,ll r){
        if(l>r)swap(l,r);
        return sum(r)-sum(l-1);
    }
    ll sum(ll index){
        ll ret=0;
        for(;index>=0;index=(index&(index+1))-1){
            ret+=tree[index];
        }
        return ret;
    }
};
vector<ll>ans;
vector<ll>arr;
vector<array<ll,3>>query;
void solve(){
    ll n=arr.size();
    ll q=ans.size();
    vector<node>a(n+q);
    for(ll i=0;i<n;i++){
        a[i].val=arr[i];
        a[i].pos=-1;
        a[i].left=-1;
        a[i].right=i;
    }
    for(ll i=n;i<q+n;i++){
        a[i].val=query[i-n][2];
        a[i].pos=i-n;
        a[i].left=query[i-n][0];
        a[i].right=query[i-n][1];
    }
    sort(a.begin(),a.end(),opt);
    BIT b(n);
    for(int i=0;i<n+q;i++){
        if(a[i].pos!=-1){
            ans[a[i].pos]=b.sum(a[i].right,a[i].left);
        }else{
            b.add(a[i].right,1);
        }
    }
}
int main(){
    ll n;cin>>n;
    ll q;cin>>q;
    vector<ll>brr(n);
    ans.resize(q);
    arr.resize(n);
    query.resize(q);
    ll inf=2ll<<60;
    unordered_map<ll,ll>mp;
    for(ll i=0;i<n;i++){
        cin>>brr[i];
        mp[brr[i]]=inf;
    }
    for(ll i=n-1;i>=0;i--){
        arr[i]=mp[brr[i]];
        mp[brr[i]]=i;
    }
    for(ll i=0;i<q;i++){
        cin>>query[i][0]>>query[i][1];
        query[i][0]--,query[i][1]--;
        query[i][2]=query[i][1];
    }
    solve();
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }
}
