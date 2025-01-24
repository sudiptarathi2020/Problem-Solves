
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
const int N=100050;
const int inf=N<<2;
int tree[N];
int mp[N];
struct node{
    int value,pos,left,right;
    node(){}
    node(int _value,int _pos,int _left,int _right){
        value=_value;
        pos=_pos;
        left=_left;
        right=_right;
    }
};
bool comp(node a,node b){
    if(a.value>b.value)return true;
    else if(a.value<b.value)return false;
    return a.left>b.left;
}
void init(int n){
    for(int i=0;i<n+10;i++){
        tree[i]=0;
    }
}
void upd(int pos,int n){
    for(int i=pos;i<n;i=i|(i+1)){
        tree[i]+=1;
    }
}
int query(int left,int right,int n){
    int sum=0;
    for(;right>=0;right=(right&(right+1))-1){
        sum+=tree[right];
    }
    left--;
    for(;left>=0;left=(left&(left+1))-1){
        sum-=tree[left];
    }
    return sum;
}
void sol(int test){
    int n,q;cin>>n>>q;
    int a[n],arr[n];
    pii queries[q];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(auto &x:queries){
        cin>>x.first>>x.second;
        x.first--,x.second--;
    }
    for(int i:a){
        mp[i]=inf;
    }
    for(int i=n-1;i>=0;i--){
        arr[i]=mp[a[i]];
        mp[a[i]]=i;
    }
    vector<node>W(n+q);
    for(int i=0;i<n;i++){
        W[i]=node(arr[i],-1,-1,i);
    }
    for(int i=0;i<q;i++){
        W[i+n]=node(queries[i].second,i,queries[i].first,queries[i].second);
    }
    sort(W.begin(),W.end(),comp);
    init(n);
    int ans[q];
    for(int i=0;i<n+q;i++){
        if(W[i].pos==-1){
            upd(W[i].right,n);
        }else{
            ans[W[i].pos]=query(W[i].left,W[i].right,n);
        }
    }
    cout<<"Case "<<test<<": "<<endl;
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
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

