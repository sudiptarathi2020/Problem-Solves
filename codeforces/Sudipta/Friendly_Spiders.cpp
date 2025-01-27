#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define mkp make_pair
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
#define IN cin
#define out cout
#define elif else if
#define yes cout<<"yes\n";
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define no cout<<"no\n";
#define fst first
#define scnd second
#define all(s) (s).begin(),(s.end())
#define sz(x) (ll)(x).size();
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define FORd(i,a,b) for(int i=a;i>=b;i--)
#define F0Rd(i,a) for(int i=a;i>=0;i--)
using namespace std;
const ll inf=LLONG_MAX;
const ll ninf=LLONG_MIN;
const ll N=3e5+10;
const ll mod=1e9+7;
typedef pair<ll,ll> pl;
typedef set<ll> st;
typedef queue<ll> ql;
typedef queue<pl> qpl;
typedef stack<ll> stk;
typedef stack<pl> stkp;
typedef priority_queue<ll> pq;
typedef priority_queue<ll,vector<ll>,greater<ll>> rpq;
typedef priority_queue<pl> pql;
typedef priority_queue<pl,vector<pl>,greater<pl>> rpql;
typedef set<pl> stp;
typedef vector<ll> vl;
typedef set<ll,greater<ll>> rst;
typedef set<pl,greater<pl>> rstp;
typedef vector<pl> vpl;
typedef vector<string> vs;
vector<int>v[N];
vector<int>prms(N+1);
vector<int>getdiv(int a){
    vector<int>ans;
    while(a!=prms[a]){
        ans.push_back(prms[a]);
        int k=prms[a];
        while(a%k==0){
            a/=k;
        }
    }
    if(a!=1){
        ans.push_back(a);
    }
    return ans;
}
void sol(ll test){

    return; 
}
int main(){
    for(int i=0;i<N;i++){
        prms[i]=i;
    }
    prms[0]=1;
    for(int i=2;i*i<=N;i++){
        if(prms[i]==i){
            for(int j=i*2;j<=N;j+=i){
                prms[j]=min(prms[j],prms[i]);
            }
        }
    }
    int n;cin>>n;
    vector<int>arr(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]=i+1;
        vector<int>ans=getdiv(arr[i]);
        for(int x:ans){
            v[x].push_back(arr[i]);
            v[arr[i]].push_back(x);
        }
    }
    int a,b;cin>>a>>b;
    int aa=arr[a-1],bb=arr[b-1];
    if(a==b){
        cout<<"1\n";
        cout<<a<<endl;
        return 0;
    }
    if(aa==1 or bb==1){
        cout<<"-1\n";
        return 0;
    }
    if(__gcd(aa,bb)!=1){
        cout<<"2\n";
        cout<<a<<" "<<b<<endl;
        return 0;
    }
    vector<int>level(N+1,-1);
    vector<int>path(N+1);
    vector<bool>vis(N+1,0);
    path[aa]=-1;
    queue<int>q;
    q.push(aa);
    level[aa]=1;
    while(q.size()){
        int x=q.front();
        q.pop();
        if(vis[x]){
            continue;
        }
        vis[x]=true;
        for(int u:v[x]){
            if(!vis[u] and level[u]==-1){
                level[u]=level[x]+1;
                path[u]=x;
                q.push(u);
            }
        }
    }
    if(!vis[bb]){
        cout<<"-1\n";
        return 0;
    }
    vector<int>ans;
    while(bb!=-1){
        ans.push_back(bb);
        bb=path[bb];
    }
    reverse(all(ans));
    vector<int>ans1;
    ans1.push_back(ans.front());
    for(int i=1;i<(int)ans.size()-1;i++){
        if(prms[ans[i]]!=ans[i]){
            ans1.push_back(ans[i]);
        }
    }
    ans1.push_back(ans.back());
    cout<<ans1.size()<<endl;
    for(int i=0;i<(int)ans1.size();i++){
        if(i==0){
            cout<<a<<" ";
            continue;
        }
        if(i==(int)ans1.size()-1){
            cout<<b<<" ";
            continue;
        }
        cout<<mp[ans1[i]]<<" ";
    }
    cout<<endl;
    
}
























 