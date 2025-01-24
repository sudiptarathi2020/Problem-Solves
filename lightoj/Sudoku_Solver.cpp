
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
const int N=9;
int arr[N][N];
vector<pii>khalighor;
bool is_valid(int x,int y,int value){
    for(int i=0;i<N;i++){
        if(arr[x][i]==value or arr[i][y]==value){
            return false;
        }
    }
    for(int i=3*(x/3);i<3+3*(x/3);i++){
        for(int j=3*(y/3);j<3+3*(y/3);j++){
            if(arr[i][j]==value){
                return false;
            }
        }
    }
    return true;
}
pii find_empty_location(){
    int Min=10,cnt=0;
    pii X;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]==-1){
                cnt=0;
                for(int k=1;k<=N;k++){
                    if(is_valid(i,j,k)){
                        cnt++;
                    }
                }
                if(cnt<Min){
                    Min=cnt;
                    X.first=i,X.second=j;
                }
            }
        }
    }
    if(Min<10){
        return X;
    }else{
        return pii(-1,-1);
    }
}
bool solve(int x){
    pii X=find_empty_location();
    if(X.first==-1)return true;
    for(int i=1;i<=N;i++){
        if(is_valid(X.first,X.second,i)){
            arr[X.first][X.second]=i;
            if(solve(x)){
                return true;
            }
            arr[X.first][X.second]=-1;
        }
    }
    return false;
}
void sol(int test){
    khalighor.clear();
    string s[N];
    for(auto &x:s)cin>>x;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(s[i][j]=='.'){
                arr[i][j]=-1;
                khalighor.push_back(pii(i,j));
            }else{
                arr[i][j]=s[i][j]-'0';
            }
        }
    }
    solve(0);
    cout<<"Case "<<test<<": \n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
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

