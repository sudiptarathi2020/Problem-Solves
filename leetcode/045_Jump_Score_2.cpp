#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int jump(vector<int>& nums){
            size_t n= nums.size();
            vector<vector<int>>adj(n);
            vector<bool>vis(n);
            vector<int>level(n);
            for(size_t i=0;i<n;i++){
                for(int j=i+1;j<=min(i+nums[i],n-1);j++){
                    adj[i].push_back(j);
                }
            }
            queue<int>q;
            q.push(0);
            level[0]=0;
            vis[0]=true;
            while(q.size()){
                int v= q.front();
                q.pop();
                for(int x:adj[v]){
                    if(!vis[x]){
                        vis[x]=true;
                        q.push(x);
                        level[x]=level[v]+1;
                    }
                }
            }
            return level[n-1];
        }
};
int main(){
}
