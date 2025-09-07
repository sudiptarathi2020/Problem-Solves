#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool dfs(int source,vector<int>adj[],vector<int>&visited,vector<int>&result){
            visited[source]=1;
            for(int u:adj[source]){
                if(visited[u]==0){
                    if(dfs(u,adj,visited,result))return true;
                }else if(visited[u]==1){
                    return true;
                }
            }
            visited[source]=2;
            result.push_back(source);
            return false;
        }
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<int>adj[numCourses];
            vector<int>visited(numCourses,0);
            for(vector<int>prerequisite: prerequisites){
                adj[prerequisite[1]].push_back(prerequisite[0]);
            }
            vector<int>result;
            for(int i=0;i<numCourses;i++){
                if(!visited[i] and dfs(i,adj,visited,result)){
                    return {};
                }
            }
            reverse(result.begin(),result.end());
            return result;
        }

};
int main(){
    Solution sol;
    int n,m;cin>>n>>m;
    vector<vector<int>>prerequisites(m);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        u--,v--;
        prerequisites[i].push_back(v);
        prerequisites[i].push_back(u);
    }
    vector<int>ans = sol.findOrder(n,prerequisites);
    if(ans.size())for(int x:ans)cout<<x+1<<" ";
    else{cout<<"IMPOSSIBLE";}
}
