
#include<bits/stdc++.h>
#define ll long long
#define lc node+1
#define rc node+2*(mid-start+1)
using pii=std::pair<int,int>;
using namespace std;
const int N=1e5+10;
struct Data{
    int mx,cnt;
    Data(){mx=0,cnt=0;}
    Data(int _mx,int _cnt):mx(_mx),cnt(_cnt){}
};
Data combine(Data a,Data b){
    Data ans;
    if(a.mx>b.mx){
        ans=a;
    }else if(a.mx<b.mx){
        ans=b;
    }else{
        ans.mx=a.mx;
        ans.cnt=a.cnt+b.cnt;
    }
    return ans;
}
Data tree[N<<1];
void build(int node,int start,int end,int a[]){
    if(start==end){
        tree[node]=Data(a[start],1);
    }else{
        int mid=(start+end)>>1;
        build(lc,start,mid,a);
        build(rc,mid+1,end,a);
        tree[node]=combine(tree[lc],tree[rc]);
    }
}
Data query(int node,int start,int end,int left,int right){
    if(left>right)return Data(0,0);
    if(start==left and end==right){
        return tree[node];
    }
    int mid=(start+end)>>1;
    if(right<=mid){
        return query(lc,start,mid,left,right);
    }else if(mid<left){
        return query(rc,mid+1,end,left,right);
    }else{
        return combine(query(lc,start,mid,left,mid),query(rc,mid+1,end,mid+1,right));
    }
}
void sol(int test){
    int n,c,q;cin>>n>>c>>q;
    int a[n],b[n],sesh[n];
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0 or a[i]!=a[i-1]){
            b[i]=1;
        }else{
            b[i]=b[i-1]+1;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1 or a[i]!=a[i+1]){
            sesh[i]=i;
        }else{
            sesh[i]=sesh[i+1];
        }
    }
    build(0,0,n-1,b);
    cout<<"Case "<<test<<": \n";
    while(q--){
        int left,right;cin>>left>>right;
        left--,right--;
        if(sesh[left]+1<=right){
            Data a;
            a.mx=sesh[left]-left+1;
            a.cnt=1;
            Data b=query(0,0,n-1,sesh[left]+1,right);
            Data ans=combine(a,b);
            cout<<ans.mx<<endl;
        }else{
            cout<<right-left+1<<endl;
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

