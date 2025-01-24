
#include<bits/stdc++.h>
#include <queue>
#define ll long long
#define lc node<<1
#define rc node<<1|1
using namespace std;
const int N=100010;
struct vertex{
    ll x,lz;
    vertex(){x=lz=0;}
};
vertex tree[N<<2];
void init(int n){
    for(int i=0;i<=(n<<2);i++){
        tree[i].x=tree[i].lz=0;
    }
}
void prop(int node,int start,int end){
    if(tree[node].lz){
        tree[node].x+=(long long)(end-start+1)*tree[node].lz;
        if(start!=end){
            int mid=(start+end)>>1;
            tree[lc].lz+=tree[node].lz;
            tree[rc].lz+=tree[node].lz;
        }
    }
    tree[node].lz=0;
}
void upd(int node,int start,int end,int left,int right,ll val){
    prop(node,start,end);
    int mid=(start+end)>>1;
    if(start==left and end==right){
        tree[node].x+=(ll)(end-start+1)*val;
        if(start!=end){
            tree[lc].lz+=val;
            tree[rc].lz+=val;
        }
        return ;
    }
    if(right<=mid){
        upd(lc,start,mid,left,right,val);
        prop(rc,mid+1,end);
    }else if(mid<left){
        upd(rc,mid+1,end,left,right,val);
        prop(lc,start,mid);
    }else{
        upd(lc,start,mid,left,mid,val);
        upd(rc,mid+1,end,mid+1,right,val);
    }
    tree[node].x=tree[lc].x+tree[rc].x;
}
ll query(int node,int start,int end,int left,int right){
    prop(node,start,end);
    if(start==left and end==right){
        return tree[node].x;
    }
    int mid=(start+end)>>1;
    if(right<=mid){
        return query(lc,start,mid,left,right);
    }else if(mid<left){
        return query(rc,mid+1,end,left,right);
    }else{
        return query(lc,start,mid,left,mid)+query(rc,mid+1,end,mid+1,right);
    }
}
void sol(int test){
    int n,q;cin>>n>>q;
    init(n);
    cout<<"Case "<<test<<": \n";
    while(q--){
        int choice;cin>>choice;
        if(choice==0){
            int x,y,val;
            cin>>x>>y>>val;
            upd(1,0,n-1,x,y,(ll)val);
        }else{
            int x,y;cin>>x>>y;
            cout<<query(1,0,n-1,x,y)<<endl;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}

