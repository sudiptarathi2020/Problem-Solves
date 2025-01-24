
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int tree[N<<2],arr[N];
void build(int node,int start,int end){
    if(start==end){
        tree[node]=arr[start];
    }else{
        int mid=(start+end)>>1;
        build(node<<1,start,mid);
        build((node<<1)^1,mid+1,end);
        tree[node]=tree[node<<1]+tree[(node<<1)|1];
    }
}
void upd(int node,int start,int end,int pos,int value){
    while(start!=end){
        tree[node]+=value;
        int mid=(start+end)>>1;
        if(pos<=mid){
            node=node<<1;
            end=mid;
        }else{
            node=(node<<1)^1;
            start=mid+1;
        }
    }
    tree[node]+=value;
}
int query(int node,int start,int end,int L,int R){
    if(start==L and end==R){
        return tree[node];
    }
    int mid=(start+end)>>1;
    if(R<=mid){
        return query(node<<1,start,mid,L,R);
    }else if(mid<L){
        return query((node<<1)^1,mid+1,end,L,R);
    }else{
        return query(node<<1,start,mid,L,mid)+query((node<<1)^1,mid+1,end,mid+1,R);
    }
}
int main(){
    int t;cin>>t;
    for(int test=1;test<=t;test++){
        int n,q;cin>>n>>q;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<"Case "<<test<<":\n";
        build(1,0,n-1);
        while(q--){
            int ch;cin>>ch;
            if(ch==1){
                int pos;cin>>pos;
                int value=query(1,0,n-1,pos,pos);
                cout<<value<<endl;
                upd(1,0,n-1,pos,-value);
            }else if(ch==2){
                int pos,value;cin>>pos>>value;
                upd(1,0,n-1,pos,value);
            }else{
                int L,R;cin>>L>>R;
                cout<<query(1,0,n-1,L,R)<<endl;
            }
        }
    }
}


























