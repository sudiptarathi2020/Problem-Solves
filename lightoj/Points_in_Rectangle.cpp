
#include<bits/stdc++.h>
using namespace std;
const int N=1010;
struct bit{
    vector<vector<int>>tree;
    bit(){
        tree.resize(N,vector<int>(N));
    }
    void add(int i,int j){
        for(int x=i;x<N;x=x|(x+1)){
            for(int y=j;y<N;y=y|(y+1)){
                tree[x][y]+=1;
            }
        }
    }
    int sum(int i,int j){
        int ret=0;
        for(int x=i;x>=0;x=(x&(x+1))-1){
            for(int y=j;y>=0;y=(y&(y+1))-1){
                ret+=tree[x][y];
            }
        }
        return ret;
    }
    int sum(int x1,int y1,int x2,int y2){
        return sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1);
    }
};
int main(){
    int t=1;cin>>t;
    for(int test=1;test<=t;test++){
        bit B;
        vector<vector<bool>>vis(N,vector<bool>(N));
        cout<<"Case "<<test<<": \n";
        int Q;cin>>Q;
        while(Q--){
            int ch=0;cin>>ch;
            if(ch==0){
                int a,b;cin>>a>>b;
                if(vis[a][b])continue;
                vis[a][b]=true;
                B.add(a,b);
            }else{
                int a,b,c,d;cin>>a>>b>>c>>d;
                cout<<B.sum(a,b,c,d)<<endl;
            }

        }
    }
}
