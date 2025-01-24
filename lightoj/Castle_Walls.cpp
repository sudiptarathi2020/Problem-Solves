
#include<bits/stdc++.h>
const int N=200050;
int bit[N];
void upd(int pos){
    for(int i=pos;i<N;i=i|(i+1)){
        bit[i]+=1;
    }
}
int sum(int L,int R){
    int ans=0;
    for(;R>=0;R=(R&(R+1))-1){
        ans+=bit[R];
    }
    for(L=L-1;L>=0;L=(L&(L+1))-1){
        ans-=bit[L];
    }
    return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);std::cout.tie(NULL);
    int t;std::cin>>t;
    for(int ii=1;ii<=t;ii++){
        int n,m;std::cin>>n>>m;
        std::pair<int,int>pos[n+m];
        for(int i=0;i<n+m;i++){
            int x,y;std::cin>>x>>y;
            x--,y--;
            if(i<n){
                pos[x]={1,y};
            }else{
                pos[x]={0,y};
            }
        }
        long long ans=0;
        for(int i=0;i<n+m;i++){
            if(pos[i].first==1){
                upd(pos[i].second);
            }else{
                ans+=(long long)sum(pos[i].second,N-1);
            }
        }
        memset(bit,0,sizeof(bit));
        for(int i=n+m-1;i>=0;i--){
            if(pos[i].first==1){
                upd(pos[i].second);
            }else{
                ans+=(long long)sum(0,pos[i].second);
            }
        }
        std::cout<<"Case "<<ii<<": "<<ans<<std::endl;
        memset(bit,0,sizeof(bit));
    }
}

