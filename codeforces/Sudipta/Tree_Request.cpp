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
#define Yes cout<<"Yes\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define no cout<<"no\n";
#define fst first
#define scnd second
#define all(s) (s).begin(),(s.end())
#define sz(x) (ll)(x).size();
#define FOR(i,a,b) for(ll i=a;i<(b);i++)
#define F0R(i,a) for(ll i=0;i<(a);i++)
#define FORd(i,a,b) for(ll i=a;i>=b;i--)
#define F0Rd(i,a) for(ll i=a;i>=0;i--)
using namespace std;
const ll inf=LLONG_MAX;
const ll ninf=LLONG_MIN;
const ll N=5e5+10;
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
vector<ll>v[N];
vector<pair<ll,pair<ll,ll>>>path(N);
vector<pair<ll,ll>>ver(N);;
vector<bool>vis(N);
ll timer=1;
void dfs(ll source,ll depth){
    vis[source]=true;
    ver[source].first=timer; 
    path[source].first=depth;
    path[source].second.first=timer;
    timer++;
    for(ll x:v[source]){
        if(!vis[x]){
            dfs(x,depth+1);
        }
    }
    path[source].second.second=timer;
    ver[source].second=timer;
    timer++;
}
void sol(ll test){
    ll n;cin>>n;
    ll q;cin>>q;
    
    for(ll i=2;i<=n;i++){
        ll a;cin>>a;
        v[a].pb(i);
    }
    string s;cin>>s;
    dfs(1,1);
    vector<pair<ll,pair<ll,ll>>>ans;
    for(ll i=1;i<=n;i++){
        ans.push_back(mkp(path[i].first,mkp(path[i].second.first,i)));
    }
    sort(all(ans));
    //for(auto it:ans){
        //cout<<it.second.second<<" "<<it.second.first<<" "<<it.first<<" "<<endl;
    //}
    cout<<endl;
    ll real[26][n+1];
    memset(real,0,sizeof(real));
    for(ll i=0;i<n;i++){
        real[s[ans[i].second.second-1]-'a'][i]=1;
    }
    for(ll i=0;i<26;i++){
        for(ll j=0;j<=n;j++){
            if(j==0){
                continue;
            }
            real[i][j]+=real[i][j-1];
        }
    }
    while(q--){
        ll a,b;cin>>a>>b;
        ll start=ver[a].first;
        ll en=ver[a].second;
        auto it=lb(all(ans),mkp(b,mkp(start,(ll)0)));
        ll ind=it-ans.begin();
        auto itt=lb(all(ans),mkp(b,mkp(en,(ll)0)));
        ll ind1=itt-ans.begin()-1;
        if(ind>=ind1){
			cout<<"Yes\n";
			continue;
		}else{
			bool sobjur=true;
			bool sobbijur=true;
			bool sobone=true;
			ll bijur=0;
			ll jur=0;
			for(ll i=0;i<26;i++){
				ll as=0;
				if(ind==0){
					as=real[i][ind1];
				}else{
					as=real[i][ind1]-real[i][ind-1];
				}
				sobjur&=(as%2==0);
				sobbijur&=(as%2==1);
				sobone&=(as==1);
				bijur+=(as%2==1);
				jur+=(as%2==0);
			}
			if(sobone){
				cout<<"Yes\n";
				continue;
			}
			if(sobjur){
				cout<<"Yes\n";
				continue;
			}
			if(bijur==1){
				cout<<"Yes\n";
				continue;
			}
			cout<<"No\n";
		}
		
        //cout<<ind<<" "<<ind1<<endl;
  }
}
int  main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t=1;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}

 