//https://codeforces.com/problemset/problem/438/D
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<ll,ll>;
using namespace std;
const ll N=100010;
struct node{
    ll sum,mn;
    node():sum(0),mn(0){}
    node(ll val){
        sum=val;
        mn=val;
    }
}tree[N<<2];
ll arr[N];
node combine(node a,node b){
    node temp;
    temp.sum=a.sum+b.sum;
    temp.mn=max(a.mn,b.mn);
    return temp;
}
void build(ll start,ll end,ll Node=1){
    if(start==end){
        tree[Node]=node(arr[start]);
    }else{
        ll mid=(start+end)>>1;
        build(start,mid,Node<<1);
        build(mid+1,end,Node<<1|1);
        tree[Node]=combine(tree[Node<<1],tree[Node<<1|1]);
    }
}
void upd(ll Node,ll start,ll end,ll left,ll right,ll val){

    if(start>right || end< left)return;
    if(start==end){
        tree[Node]=node(tree[Node].sum%val);
        return;
    }
    ll mid=(start+end)>>1;
    if(tree[Node<<1].mn>=val){
        upd(Node<<1,start,mid,left,right,val);
    }
    if(tree[Node<<1|1].mn>=val){
        upd(Node<<1|1,mid+1,end,left,right,val);
    }
    tree[Node]=combine(tree[Node<<1],tree[Node<<1|1]);
}
void upd(ll Node,ll start,ll end,ll pos,ll val){
    if(start==end){
        tree[Node]=node(val);
        return;
    }
    ll mid=(start+end)>>1;
    if(pos<=mid){
        upd(Node<<1,start,mid,pos,val);
    }else if(mid<pos){
        upd(Node<<1|1,mid+1,end,pos,val);
    }
    tree[Node]=combine(tree[Node<<1],tree[Node<<1|1]);

}
node sum(ll Node,ll start,ll end,ll left,ll right){
    if(start==left and end==right){
        return tree[Node];
    }
    ll mid=(start+end)>>1;
    if(right<=mid){
        return sum(Node<<1,start,mid,left,right);
    }else if(mid<left){
        return sum(Node<<1|1,mid+1,end,left,right);
    }else{
        return combine(sum(Node<<1,start,mid,left,mid),sum(Node<<1|1,mid+1,end,mid+1,right));
   }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,m;cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    build(0,n-1);
    while(m--){
        ll choice;cin>>choice;
        if(choice==1){
            ll a,b;cin>>a>>b;
            a--,b--;
            cout<<sum(1,0,n-1,a,b).sum<<endl;
        }else if(choice==2){
            ll a,b,c;cin>>a>>b>>c;
            a--,b--;
            upd(1,0,n-1,a,b,c);
        }else{
            ll a,b;cin>>a>>b;
            upd(1,0,n-1,a-1,b);
        }
    }
    return 0;
}

