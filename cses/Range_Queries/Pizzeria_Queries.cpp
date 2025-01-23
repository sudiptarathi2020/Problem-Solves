
#include<iostream>
#include<climits>
using namespace std;
const int N = 200050;
int tree[N*4][2],arr[N],n,q;
void build(int node,int st,int en){
    if(st==en){
        tree[node][0]=st+arr[st];
        tree[node][1]=arr[st]+(n-st+1);
    }else{
        int mid=(st+en)>>1;
        build(node*2,st,mid);
        build(node*2+1,mid+1,en);
        tree[node][0]=min(tree[node*2][0],tree[node*2+1][0]);
        tree[node][1]=min(tree[node*2][1],tree[node*2+1][1]);
    }
}
void upd(int node,int st,int en,int pos,int val){
    if(st==en){
        tree[node][0]=st+val;
        tree[node][1]=val+(n-pos+1);
    }else{
        int mid=(st+en)>>1;
        if(pos<=mid){
            upd(node*2,st,mid,pos,val);
        }
        if(pos>mid){
            upd(node*2+1,mid+1,en,pos,val);
        }
        tree[node][0]=min(tree[node*2][0],tree[node*2+1][0]);
        tree[node][1]=min(tree[node*2][1],tree[node*2+1][1]);
    }
}
int qry(int node,int st,int en,int L,int R,int I){
    if(en<L || st>R)return INT_MAX;
    if(L<=st && en<=R)return tree[node][I];
    int mid=(st+en)>>1;
    return min(qry(node*2,st,mid,L,R,I),qry(node*2+1,mid+1,en,L,R,I));
}
int main(){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    while(q--){
        int choice;cin>>choice;
        if(choice==1){
            int k,x;cin>>k>>x;
            k--;upd(1,0,n-1,k,x);
        }else{
            int k;cin>>k;k--;
            cout<<min(qry(1,0,n-1,k,n-1,0)-k,qry(1,0,n-1,0,k,1)-(n-k+1))<<endl;
        }
    }
}
