//https://codeforces.com/problemset/problem/242/E
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4")
#include<stdio.h>
#define N 100001
#define lc node+1
#define mid ((start+end)>>1)
#define rc (((mid-start+1)<<1)+node)
int tree[N<<1][21],lazy[N<<1][21],arr[N];
void build(int node,int start,int end){
    if(start==end){
        int i,j;
        for(i=0;i<21;i++){
            tree[node][i]=arr[start]&(1<<i)?1:0;
        }
    }else{
        build(lc,start,mid);
        build(rc,mid+1,end);
        for(int i=0;i<21;i++){
            tree[node][i]=tree[lc][i]+tree[rc][i];
        }
    }
}
void prop(int node,int start,int end){
    int i;
    for(i=0;i<21;i++){
        if(lazy[node][i]){
            tree[node][i]=(end-start+1)-tree[node][i];
        }
    }
    if(start!=end){
        for(i=0;i<21;i++){
            if(lazy[node][i]){
                lazy[rc][i]^=lazy[node][i];
                lazy[lc][i]^=lazy[node][i];
            }
        }
    }
    for(i=0;i<21;i++){
        lazy[node][i]=0;
    }

}
void upd(int node,int start,int end,int left,int right,int value){
    prop(node,start,end);
    int i;
    if(start==left && end==right){
        for(i=0;i<21;i++){
            if((value&(1<<i))){
                tree[node][i]=(end-start+1)-tree[node][i];
                if(start!=end){
                    lazy[lc][i]^=1;
                    lazy[rc][i]^=1;
                }
            }
        }

        return;
    }
    if(right<=mid){
        upd(lc,start,mid,left,right,value);
        prop(rc,mid+1,end);
    }else if(mid<left){
        upd(rc,mid+1,end,left,right,value);
        prop(lc,start,mid);
    }else{
        upd(lc,start,mid,left,mid,value);
        upd(rc,mid+1,end,mid+1,right,value);
    }
    for(i=0;i<21;i++){
        tree[node][i]=tree[lc][i]+tree[rc][i];
    }
}
long long q(int node,int start,int end,int left,int right){
    prop(node,start,end);
    if(start==left && end==right){
        int i;
        long long ans=0;
        for(i=0;i<21;i++){
            ans=ans+(long long)tree[node][i]*(long long)(1<<i);
        }
        return ans;
    }
    if(right<=mid){
        return q(lc,start,mid,left,right);
    }else if(mid<left){
        return q(rc,mid+1,end,left,right);
    }else{
        return q(lc,start,mid,left,mid)+q(rc,mid+1,end,mid+1,right);
    }
}
int main(){
    int j,qq,i,n;scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    build(0,0,n-1);
    scanf("%d",&qq);
    while(qq--){
        int choice;scanf("%d",&choice);
        if(choice==2){
            int l,r,x;scanf("%d%d%d",&l,&r,&x);
            l--,r--;
            upd(0,0,n-1,l,r,x);
        }else{
            int l,r;scanf("%d%d",&l,&r);
            l--,r--;
            long long ans=q(0,0,n-1,l,r);
            printf("%lld\n",ans);
        }
    }
}

