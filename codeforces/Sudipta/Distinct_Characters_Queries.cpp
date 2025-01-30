//dedicated to Rubayed All Islam Munna
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define N '\n'
#define Fast ios::sync_with_stdio(false); cin.tie(NULL)
#define File freopen("in.txt","r",stdin)
const ll M=1e5+9;
struct seg
{
    vector<ll>tree;
    ll n;
    seg(){
        this->n=M;
        tree.assign(4*n,0);
    }
    void update(ll pos,ll val)
 
    {
 
        update(1,0,n-1,pos,val);
 
    }
 
    void update(ll node,ll st,ll en,ll pos,ll val){
 
        if(st==en){
 
            tree[node]+=val;
 
            return;
 
        }
 
        ll mid=(st+en)>>1;
 
        if(pos<=mid){
 
            update(2*node,st,mid,pos,val);
 
        }else{
 
            update(2*node+1,mid+1,en,pos,val);
 
        }
 
        tree[node]=tree[2*node]+tree[2*node+1];
 
    }
 
    ll q(ll l,ll r){
 
        return q(1,0,n-1,l,r);
 
    }
 
    ll q(ll node,ll st,ll en,ll l,ll r){
 
        if(l>r){
 
            return 0;
 
        }
 
        if(st==l&&en==r)
 
        {
 
            return tree[node];
 
        }
 
        ll mid=(st+en)>>1;
 
 
        if(r<=mid)
 
        {
 
            return q(2*node,st,mid,l,r);
 
        }
 
        else if(l>mid)
 
        {
 
            return q(2*node+1,mid+1,en,l,r);
 
        }
 
        else
 
        {
 
            return q(2*node,st,mid,l,mid)+q(2*node+1,mid+1,en,mid+1,r);
 
        }
 
    }
 
};
void solve(ll tst)
{
    vector<seg>v(26);
    vector<char>s;
    string ss;cin>>ss;
    for(int i=0;i<(int)ss.size();i++){
        ll k=ss[i]-'a';
        s.push_back(ss[i]);
        v[k].update(i,1);
    }
    int q;cin>>q;
    while(q--){
        ll ch;cin>>ch;
        if(ch==1){
 
            ll ind;
 
            char c;
            cin>>ind>>c;
            char x=s[ind-1];
            v[c-'a'].update(ind-1,1);
            v[x-'a'].update(ind-1,-1);
            s[ind-1]=c;
            
            
        }else{
            ll total=0;
            ll l,r;cin>>l>>r;
            for(int i=0;i<26;i++){
                if(v[i].q(l-1,r-1)){
					
                    total++;
                }
            }
            cout<<total<<endl;
        }
    }
}
int main()
{
 
    Fast;
 
    //File;
 
    ll t=1;
 
    //cin>>t;
 
    ll tst=0;
 
    while(t--)
 
    {
 
        solve(++tst);
 
    }
 
    return 0;
 
}
