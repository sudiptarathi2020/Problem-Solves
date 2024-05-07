//https://codeforces.com/problemset/problem/1608/C
#include<bits/stdc++.h>
using namespace std;
struct SCC{
    int n;
    vector<vector<int>>adj,rev_adj,scc;
    vector<int>order,vis,s;
    SCC(){}
    SCC(int _n){
        this->n=_n;
        adj.resize(n+1);
        rev_adj.resize(n+1);
        vis.resize(n+1);
    }
    void add(int u,int v){
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
    void dfs(int source){
        vis[source]=true;
        for(int u:adj[source]){
            if(vis[u])continue;
            dfs(u);
        }
        order.push_back(source);
    }
    void rdfs(int source){
        vis[source]=true;
        s.push_back(source);
        for(int u:rev_adj[source]){
            if(vis[u])continue;
            rdfs(u);
        }
    }
    void DFS(){
        for(int i=0;i<n;i++){
            if(!vis[i]){
               
                dfs(i);
            }
        }
    }
    void RDFS(){
        vis.assign(n+1,0);
        reverse(order.begin(),order.end());
        for(int u:order){
            if(!vis[u]){
				s.clear();
                rdfs(u);
                scc.push_back(s);
                //~ for(int b:s){
					//~ cout<<b<<" ";
				//~ }
				//~ cout<<endl;
            }
        }
    }
    void init(){
        DFS();
		//cout<<endl;
        RDFS();
    }
};
void sol(){
    int n;cin>>n;
    vector<pair<int,int>>arr(n),brr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>arr[i].second;
        brr[i]=arr[i];
    }
    vector<int>order(n);
    iota(order.begin(),order.end(),0);
    sort(order.begin(),order.end(),[&](int a,int b){
        return arr[a]>arr[b];});
    SCC S(n);
    for(int i=0;i<n-1;i++){
        S.add(order[i],order[i+1]);
    }
    //~ for(int i=0;i<n;i++){
		//~ cout<<order[i]<<" ";
	//~ }
	//cout<<endl;
    for(auto &x:arr){
        swap(x.first,x.second);
    }
    sort(order.begin(),order.end(),[&](int a,int b){
        return arr[a]>arr[b];});
    for(int i=0;i<n-1;i++){
        S.add(order[i],order[i+1]);
    }
    //~ for(int i=0;i<n;i++){
		//~ cout<<order[i]<<" ";
	//~ }
	//cout<<endl;
    S.init();
    //~ for(int i=0;i<(int)S.scc.size();i++){
		//~ cout<<i<<": ";
		//~ for(auto &x:S.scc[i]){
			//~ cout<<x<<" ";
		//~ }
		//~ cout<<endl;
	//~ }
    map<int,int>mp;
    map<int,int>mp1;
    for(int i=0;i<(int)S.scc.size();i++){
        for(auto &x:S.scc[i]){
			mp[x]=i;
		}
        mp1[i]=true;
    }
    for(int i=0;i<n;i++){
        for(auto &x:S.adj[i]){
            if(mp[i]!=mp[x])mp1[mp[x]]=false;
        }
    }
    for(int i=0;i<n;i++){
        cout<<(mp1[mp[i]]?1:0);
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;cin>>t;while(t--)sol();
    return 0;
}
