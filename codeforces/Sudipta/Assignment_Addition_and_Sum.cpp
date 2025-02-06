
#include<bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define mid ((start+end)>>1)
#define lc (node+1)
#define rc (((mid-start+1)<<1)+node)
const i64 N = 1e5+5;
array<i64,3> seg[N<<1];
void append(i64 node, i64 start, i64 end, i64 val, bool type){
    if(type){
        seg[node]={0,0,type};
    }
    seg[node][0]+=val*(end-start+1);
    seg[node][1]+=val;
}
void push(i64 node, i64 start, i64 end){
    append(lc,start,mid,seg[node][1],seg[node][2]);
    append(rc,mid+1,end,seg[node][1],seg[node][2]);
    seg[node]={seg[node][0],0,false};
}
void upd(i64 node, i64 start, i64 end, i64 left, i64 right, i64 val, bool type){
    if(start>right||end<left) return;
    if(start>=left&&end<=right){
        append(node,start,end,val,type);
        return;
    }
    push(node,start,end);
    upd(lc,start,mid,left,right,val,type);
    upd(rc,mid+1,end,left,right,val,type);
    seg[node][0]=seg[lc][0]+seg[rc][0];
}
i64 query(i64 node, i64 start, i64 end, i64 left, i64 right){
    if(start>right||end<left) return 0;
    if(start>=left&&end<=right) return seg[node][0];
    push(node,start,end);
    return query(lc,start,mid,left,right)+query(rc,mid+1,end,left,right);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    i64 n,q;cin>>n>>q;
    while(q--){
        i64 choice;cin>>choice;
        if(choice==1){
            i64 l,r,v;cin>>l>>r>>v;
            upd(0,0,n-1,l,r-1,v,true);
        }else if(choice==2){
            i64 l,r,v;cin>>l>>r>>v;
            upd(0,0,n-1,l,r-1,v,false);
        }else{
            i64 l,r;cin>>l>>r;
            cout<<query(0,0,n-1,l,r-1)<<endl;
        }
    }
}
