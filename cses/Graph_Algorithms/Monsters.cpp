#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
const int inf=1001*1001;
const int mod=1e9+7;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void sol(int test){
    int n,m;cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]=inf;
        }
    }
    pii start={-1,-1};
    queue<pii>q;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<m;j++){
            if(s[i][j]=='A'){
                start={i,j};
            }else if(s[i][j]=='M'){
                a[i][j]=0;
                q.push({i,j});
            }
        }
    }
    while(q.size()){
        pii current=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=current.first+dx[i];
            int y=current.second+dy[i];
            if(x>=0 and x<n and y>=0 and y<m and a[x][y]>a[current.first][current.second]+1 and s[x][y]!='#'){
                a[x][y]=a[current.first][current.second]+1;
                q.push({x,y});
            }
        }
    }
    q.push(start);
    a[start.first][start.second]=0;
    pii father[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            father[i][j]={-1,-1};
        }
    }
    bool paisi=false;
    pii end={-1,-1};
    while(q.size() and !paisi){
        pii current=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x=current.first+dx[i];
            int y=current.second+dy[i];
            if(x>=0 and x<n and y>=0 and y<m and a[x][y]>a[current.first][current.second]+1 and s[x][y]!='#'){
                a[x][y]=a[current.first][current.second]+1;
                father[x][y]=current;
                q.push({x,y});
                if(x==0 or y==0 or x==n-1 or y==m-1){
                    paisi=true;
                    end={x,y};
                    break;
                }
            }
        }
    }
    if(start.first==0 or start.first==n-1 or start.second==0 or start.second==m-1){
        cout<<"YES\n0\n";
        return;
    }
    if(!paisi ||end.first==-1){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        string ans="";
        while(end!=start){
            pii baba=father[end.first][end.second];
            if(end==pii(baba.first+1,baba.second)){
                ans+='D';
            }else if(end==pii(baba.first,baba.second+1)){
                ans+='R';
            }else if(end==pii(baba.first-1,baba.second)){
                ans+='U';
            }else if(end==pii(baba.first,baba.second-1)){
                ans+='L';
            }
            end=baba;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    //    cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
}
 
