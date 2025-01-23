#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin>>n;
    vector<bool>used(n+1);
    vector<int>d(n+1);
    queue<int>q;
    q.push(n);
    used[n]=true;
    bool paisi=false;
    while(q.size()){
        int x=q.front();
        q.pop();
        int y=x;
        while(x){
            int p=x%10;
            x/=10;
            if(p){
                if(!used[y-p]){
                    used[y-p]=true;
                    q.push(y-p);
                    d[y-p]=d[y]+1;
                    if(y-p==0)paisi=true;
                }
            }
            if(paisi)break;
        }
        if(paisi)break;
    }
    cout<<d[0]<<endl;
    return 0;
}
