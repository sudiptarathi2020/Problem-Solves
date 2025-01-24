
#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;
const int N=11;
bool grid[N][N];
struct point{
    int x,y;
    bool operator==(const point& other)const{
        return make_pair(x,y)==make_pair(other.x,other.y);
    }
};
bool comp(point a,point b){
    return make_pair(a.x,a.y)==make_pair(b.x,b.y);
}
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
array<point,3> get(array<point,3>A,int idx,int n){
    array<point,3>B;
    bool vis[3];memset(vis,false,sizeof(vis));
    for(int i=0;i<3;i++){
        B[i].x=A[i].x+dx[idx];
        B[i].y=A[i].y+dy[idx];
        if(B[i].x<0 || B[i].x==n || B[i].y<0 || B[i].y==n || comp(B[i],A[(i+1)%3]) || comp(B[i],A[i==0?2:i-1]) || grid[B[i].x][B[i].y]){
            B[i]=A[i];
        }else{
            A[i]=B[i];
            vis[i]=true;
        }
    }
    for(int i=0;i<3;i++){
        if(vis[i])continue;
        B[i].x=A[i].x+dx[idx];
        B[i].y=A[i].y+dy[idx];
        if(B[i].x<0 || B[i].x==n || B[i].y<0 || B[i].y==n || comp(B[i],A[(i+1)%3]) || comp(B[i],A[i==0?2:i-1]) || grid[B[i].x][B[i].y]){
            B[i]=A[i];
        }else{
            A[i]=B[i];
            vis[i]=true;
        }
    }

    for(int i=0;i<3;i++){
        if(vis[i])continue;
        B[i].x=A[i].x+dx[idx];
        B[i].y=A[i].y+dy[idx];
        if(B[i].x<0 || B[i].x==n || B[i].y<0 || B[i].y==n || comp(B[i],A[(i+1)%3]) || comp(B[i],A[i==0?2:i-1])  || grid[B[i].x][B[i].y]){
            B[i]=A[i];
        }else{
            A[i]=B[i];
            vis[i]=true;
        }
    }
    return B;
}
void print(array<point,3>A,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                cout<<'X';
            }else if(make_pair(A[0].x,A[0].y)==make_pair(i,j)){
                cout<<'$';
            }else if(make_pair(A[1].x,A[1].y)==make_pair(i,j)){
                cout<<'$';
            }else if(make_pair(A[2].x,A[2].y)==make_pair(i,j)){
                cout<<'$';
            }else{
                cout<<'.';
            }
        }
        cout<<endl;
    }
    cout<<"________\n";
}
bool vis[N][N][N][N][N][N];
int dist[N][N][N][N][N][N];
void st(array<point,3>A,array<point,3>B){
    dist[A[0].x][A[0].y][A[1].x][A[1].y][A[2].x][A[2].y]=dist[B[0].x][B[0].y][B[1].x][B[1].y][B[2].x][B[2].y]+1;
}
void make(array<point,3>A){
    vis[A[0].x][A[0].y][A[1].x][A[1].y][A[2].x][A[2].y]=true;
}
bool used(array<point,3>A){
    return vis[A[0].x][A[0].y][A[1].x][A[1].y][A[2].x][A[2].y];
}
void sol(int test){
    int n;cin>>n;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            grid[i][j]=0;
        }
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++)
                for(int a=0;a<N;a++)
                    for(int b=0;b<N;b++)
                        for(int c=0;c<N;c++){
                            dist[i][j][k][a][b][c]=0;
                            vis[i][j][k][a][b][c]=0;
                        }

    string s[n];for(string &x:s)cin>>x;
    array<point,3>A;
    array<point,3>target;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='#'){
                grid[i][j]=1;
            }else if(s[i][j]=='A'){
                A[0].x=i,A[0].y=j;
            }else if(s[i][j]=='B'){
                A[1].x=i,A[1].y=j;
            }else if(s[i][j]=='C'){
                A[2].x=i,A[2].y=j;
            }else if(s[i][j]=='X'){
                target[cnt].x=i,target[cnt].y=j;
                cnt++;
            }
        }
    }
    queue<array<point,3>>q;
    q.push(A);
    make(A);
    while(q.size()){
        array<point,3>x=q.front();
        q.pop();
        for(int a=0;a<4;a++){
            array<point,3>y=get(x,a,n);
            if(used(y))continue;
            make(y);
            st(y,x);
            q.push(y);
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(j==i)continue;
                    for(int k=0;k<3;k++){
                        if(k==j or k==i)continue;
                        if(y[0]==target[i] and y[1]==target[j] and y[2]==target[k]){
                            cout<<"Case "<<test<<": "<<dist[x[0].x][x[0].y][x[1].x][x[1].y][x[2].x][x[2].y]+1<<endl;
                            return ;
                        }
                    }
                }
            }
        }
    }
    
    cout<<"Case "<<test<<": ";
    cout<<"trapped\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int test=1;
    int t;cin>>t;while(t--)sol(test++);
}

