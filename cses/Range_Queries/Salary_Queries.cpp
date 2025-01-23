#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
vector<int>tree;
#define lc node+1
#define rc node+2*(mid-start+1)
void upd(int node,int start,int end,int pos,int val){
    if(start==end){
        tree[node]+=val;
    }else{
        int mid=(start+end)>>1;
        if(pos<=mid){
            upd(lc,start,mid,pos,val);
        }else if(pos>mid){
            upd(rc,mid+1,end,pos,val);
        }
        tree[node]=tree[lc]+tree[rc];
    }
}
int query(int node,int start,int end,int left,int right){
    if(start==left and end==right){
        return tree[node];
    }else{
        int mid=(start+end)>>1;
        if(right<=mid){
            return query(lc,start,mid,left,right);
        }else if(mid<left){
            return query(rc,mid+1,end,left,right);
        }else{
            return query(lc,start,mid,left,mid)+query(rc,mid+1,end,mid+1,right);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,q;cin>>n>>q;
    vector<int>Num;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        Num.push_back(arr[i]);
    }
    vector<pair<char,pii>>queries;
    for(int i=0;i<q;i++){
        char choice;
        int a,b;cin>>choice>>a>>b;
        queries.push_back({choice,{a,b}});
        if(choice=='!'){
            Num.push_back(b);
        }else if(choice=='?'){
            Num.push_back(a);
            Num.push_back(b);
        }
    }
    sort(Num.begin(),Num.end());
    vector<int>Uni;
    for(int i=0;i<(int)Num.size();i++){
        if(Uni.size() and Uni.back()==Num[i])continue;
        Uni.push_back(Num[i]);
    }
    unordered_map<int,int>Mp;
    for(int i=0;i<(int)Uni.size();i++){
        Mp[Uni[i]]=i;
    }
    int N=Mp[Uni.back()]+10;
    tree.resize(N<<1);
    for(int i=0;i<n;i++){
        upd(0,0,N-1,Mp[arr[i]],1);
    }
    for(pair<char,pii>x:queries){
        if(x.first=='!'){
            upd(0,0,N-1,Mp[arr[x.second.first-1]],-1);
            arr[x.second.first-1]=x.second.second;
            upd(0,0,N-1,Mp[arr[x.second.first-1]],1);
        }else{
            cout<<query(0,0,N-1,Mp[x.second.first],Mp[x.second.second])<<endl;
        }
    }
    return 0;
}
