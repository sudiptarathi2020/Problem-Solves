//https://codeforces.com/problemset/problem/1833/F
#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
struct seg{
    long long N;
    vector<long long>tree;
    seg(){}
    seg(long long _N){
        this->N=_N;
        tree.resize(4*N);
    }
    seg(vector<long long>&v){
        this->N=(long long)v.size();
        tree.resize(4*N);
        build(1,0,N-1,v);
    }
    void build(long long Node,long long start,long long end,vector<long long>&v){
        if(start==end){
            tree[Node]=v[start];
            return;
        }
        long long mid=(start+end)>>1;
        build(Node<<1,start,mid,v);
        build((Node<<1)|1,mid+1,end,v);
        tree[Node]=max(tree[Node<<1],tree[(Node<<1)|1]);
    }
    long long Q(long long start,long long end){
        return Q(1,0,N-1,start,end);
    }
    long long Q(long long Node,long long start,long long end,long long Left,long long Right){
        if(start==Left and end==Right){
            return tree[Node];
        }
        long long mid=(start+end)>>1;
        if(Right<=mid){
            return Q(Node<<1,start,mid,Left,Right);
        }else if(Left>mid){
            return Q((Node<<1)|1,mid+1,end,Left,Right);
        }else{
            long long A=Q(Node<<1,start,mid,Left,mid);
            long long B=Q((Node<<1)|1,mid+1,end,mid+1,Right);
            return max(A,B);
        }
    }
};
struct SEG{
    long long N;
    vector<long long>tree;
    SEG(){}
    SEG(long long _N){
        this->N=_N;
        tree.resize(4*N);
    }
    SEG(vector<long long>&v){
        this->N=(long long)v.size();
        tree.resize(4*N);
        build(1,0,N-1,v);
    }
    void build(long long Node,long long start,long long end,vector<long long>&v){
        if(start==end){
            tree[Node]=v[start];
            return;
        }
        long long mid=(start+end)>>1;
        build(Node<<1,start,mid,v);
        build((Node<<1)|1,mid+1,end,v);
        tree[Node]=(tree[Node<<1]*tree[(Node<<1)|1])%mod;
    }
    long long Q(long long start,long long end){
        return Q(1,0,N-1,start,end);
    }
    long long Q(long long Node,long long start,long long end,long long Left,long long Right){
        if(start==Left and end==Right){
            return tree[Node];
        }
        long long mid=(start+end)>>1;
        if(Right<=mid){
            return Q(Node<<1,start,mid,Left,Right);
        }else if(Left>mid){
            return Q((Node<<1)|1,mid+1,end,Left,Right);
        }else{
            long long A=Q(Node<<1,start,mid,Left,mid);
            long long B=Q((Node<<1)|1,mid+1,end,mid+1,Right);
            return (A*B)%mod;
        }
    }
};
void sol(){
    long long N,M;
    map<long long,long long>MP;
    cin>>N>>M;
    vector<long long>arr(N),brr;
    for(auto &x:arr){
        cin>>x;
        MP[x]++;
        if(MP[x]==1){
            brr.push_back(x);
        }
    }
    stable_sort(brr.begin(),brr.end());
    vector<long long>D;
    for(long long X:brr){
        D.push_back(MP[X]);
    }
    SEG S(D);
    long long ans=0;
    for(long long i=0;i<(long long)brr.size();i++){
        long long L=i+M-1; 
        if(L>=(long long)brr.size())break;
        long long P=brr[L]-brr[i];
        if(P<M){
            ans+=S.Q(i,L);
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}
int main(){
    long long T;cin>>T;while(T--)sol();
}
