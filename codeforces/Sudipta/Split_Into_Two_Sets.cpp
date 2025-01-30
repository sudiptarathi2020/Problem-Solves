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
const ll N=2e5;
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
void sol(ll test){
    ll n;IN>>n;
    vpl arr(n);
    vl check[n+1];
    bool paisi=false;
    vl jj(n+1);
    F0R(i,n){
        IN>>arr[i].fst>>arr[i].scnd;
        check[arr[i].fst].pb(i);
        check[arr[i].scnd].pb(i);
        jj[arr[i].fst]++;
        jj[arr[i].scnd]++;
        if(arr[i].fst==arr[i].scnd){
			paisi=true;
		}
    }
    for(int i=1;i<=n;i++){
		if(jj[i]!=2){
			no
			return;
		}
	}
    if(paisi){
		no
		return;
	}
    vl v[n+1];
    FOR(i,1,n+1){
        v[check[i].front()].pb(check[i].back());
        v[check[i].back()].pb(check[i].front());
    }
    vl vis(n+1);
    vl cont(n+1);
    F0R(i,n){
        if(!vis[i]){
            vl path(n+1);
            ql q;
			path[i]=-1;
            q.push(i);
            vl tr;
            while(q.size()){
                ll x=q.front();
                q.pop();
                if(vis[x])continue;
                vis[x]=true;
                tr.pb(x);
                for(ll u:v[x]){
                    if(not vis[u]){
                        q.push(u);
                        path[u]=x;
                    }
                }
            }
            for(ll x:tr){
                if(path[x]==-1){
                    cont[x]=1;
                }else{
                    if(cont[path[x]]==1){
                        cont[x]=2;
                    }else{
                        cont[x]=1;
                    }
                }
            }
        }
    }
    vl ans1,ans2;
    F0R(i,n){
        if(cont[i]==1){
            ans1.pb(i);
        }else{
            ans2.pb(i);
        }
    }
    if(ans1.size()!=ans2.size()){
        no
        return;
    }else{
        vl ch2(n+1); 
        for(ll x:ans1){
            ch2[arr[x].fst]++;
            ch2[arr[x].scnd]++;
        }
        FOR(i,1,n+1){
            if(ch2[i]!=1){
                no
                return;
            }
        }
        yes
        return;
    }
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;cin>>t;
    FOR(i,1,t+1){
        sol(i);
    }
    return 0;
}
 
