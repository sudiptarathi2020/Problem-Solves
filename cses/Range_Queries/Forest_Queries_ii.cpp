
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
const int N=1010;
int tree[N][N];
int query(int x,int y){
    int ret=0;
    for(int i=x;i>=0;i=(i&(i+1))-1){
        for(int j=y;j>=0;j=(j&(j+1))-1){
            ret+=tree[i][j];
        }
    }
    return ret;
}
int query(int xmin,int ymin,int xmax,int ymax){
    return query(xmax,ymax)-query(xmax,ymin-1)-query(xmin-1,ymax)+query(xmin-1,ymin-1);
}
void upd(int x,int y){
    int ret=query(x,y,x,y);
    if(ret==0){
        ret=1;
    }else{
        ret=-1;
    }
    for(int i=x;i<N;i=i|(i+1)){
        for(int j=y;j<N;j=j|(j+1)){
            tree[i][j]+=ret;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;cin>>n>>m;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='*'){
                upd(i,j);
            }
        }
    }
    while(m--){
        int choice;cin>>choice;
        if(choice==2){
            int xmin,ymin,xmax,ymax;
            cin>>xmin>>ymin>>xmax>>ymax;
            xmin--,ymin--,xmax--,ymax--;
            cout<<query(xmin,ymin,xmax,ymax)<<endl;
        }else{
            int x,y;cin>>x>>y;
            upd(x-1,y-1);
        }
    }
}
