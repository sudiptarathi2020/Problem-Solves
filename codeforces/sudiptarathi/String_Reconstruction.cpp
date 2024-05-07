//https://codeforces.com/problemset/problem/827/A
#include<bits/stdc++.h>
using namespace std;
struct seg{
    int n;
    vector<pair<int,int>>tree;
    vector<pair<int,int>>lval;
    vector<bool>lazy;
    seg(){}
    void init(int _n){
        n=_n;
        tree.resize(4*n,{-1,-1});
        lval.resize(4*n);
        lazy.resize(4*n);
    }
    void upd(int start,int end,pair<int,int>val){
        upd(1,0,n-1,start,end,val);
    }
    void upd(int node,int start,int end,int left,int right,pair<int,int>val){
        if(lazy[node]){
            tree[node]=lval[node];
            if(start!=end){
                lazy[node<<1]=lazy[(node<<1)|1]=true;
                lval[node<<1]=lval[(node<<1)|1]=lval[node];
            }
            lval[node]={-1,-1};
            lazy[node]=false;
        }
        if(start==left and end==right){
            tree[node]=val;
            if(start!=end){
                lazy[node<<1]=lazy[(node<<1)|1]=true;
                lval[node<<1]=lval[(node<<1)|1]=val;
            }
            return;
        }
        int mid=(start+end)>>1;
        if(right<=mid){
            upd(node<<1,start,mid,left,right,val);
        }else if(left>mid){
            upd((node<<1)|1,mid+1,end,left,right,val);
        }else{
            upd(node<<1,start,mid,left,mid,val);
            upd((node<<1)|1,mid+1,end,mid+1,right,val);
        }
        tree[node]=min(tree[node<<1],tree[(node<<1)|1]);
    }
    pair<int,int> get(int left,int right){
        return Q(1,0,n-1,left,right);
    }
    pair<int,int> Q(int node,int start,int end,int left,int right){
        if(lazy[node]){
            tree[node]=lval[node];
            if(start!=end){
                lazy[node<<1]=lazy[(node<<1)|1]=true;
                lval[node<<1]=lval[node];
                lval[(node<<1)|1]=lval[node];
            }
            lazy[node]=false;
            lval[node]={-1,-1};
        }
        if(start==left and end==right){
            return tree[node];
        }
        int mid=(start+end)>>1;
        if(right<=mid){
            return Q(node<<1,start,mid,left,right);
        }else if(left>mid){
            return Q((node<<1)|1,mid+1,end,left,right);
        }else{
            auto A=Q(node<<1,start,mid,left,mid);
            auto B=Q((node<<1)|1,mid+1,end,mid+1,right);
            return min(A,B);
        }
    }
};seg S;
void sol(){
    int n;cin>>n;
    vector<vector<int>>arr(n);
    vector<string>s(n);
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>s[i];
        int m;cin>>m;
        arr[i].resize(m);
        for(auto &x:arr[i]){
            cin>>x;
        }
        mx=max(mx,arr[i].back()+(int)s[i].size()-1);
    }
    S.init(mx);
    for(int i=0;i<n;i++){
        for(auto x:arr[i]){
            S.upd(x-1,x-1+(int)s[i].size()-1,{i,x-1});
        }
    }
    for(int i=0;i<mx;i++){
        auto it=S.get(i,i);
        if(it.first==-1){
            cout<<"a";
            continue;
        }
        cout<<s[it.first][i-it.second];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;while(t--)sol();
}
