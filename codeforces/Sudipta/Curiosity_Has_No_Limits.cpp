#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
#define mkp make_pair
#define fst first
#define scnd second
#define all(s) (s).begin(),(s.end())
#define sz(x) (ll)(x).size();
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define F0R(i,a) for(int i=0;i<(a);i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define f0rd(i,a) for(int i=a;i>=0;i--)
using namespace std;
const ll inf=LLONG_MAX;
const ll ninf=LLONG_MIN;
typedef pair<ll,ll> pl;
typedef set<ll> st;
typedef queue<ll> ql;
typedef queue<pl> qpl;
typedef stack<ll> stk;
typedef stack<pl> stkp;
typedef priority_queue<ll> pq;
typedef priority_queue<pl> pql;
typedef set<pl> stp;
typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<string> vs;
map<pl,vector<pl>>mp;
bool check(vpl &v,vl &ans1,ll st,ll n){
    FOR(i,1,n){
        if(v[i].fst==0 and v[i].scnd==0){
            if(st==0){
                //continue;
                ans1.pb(st);
            }else{
                return false;
            }
        }else if(v[i].fst==1 and v[i].scnd==0){
            if(st==1){
                ans1.pb(st);
                st=0;
            }else{
                ans1.pb(st);
                st=1;
            }
        }else if(v[i].fst==1 and v[i].scnd==1){
            if(st==1){
                ans1.pb(st);

            }else{
                return false;
            }
        }else if(v[i].fst==0 and v[i].scnd==1){
            return false;
        }
    }
    ans1.pb(st); 
    return true;
}
void sol(){
    ll n;cin>>n;
    n--;
    vl a(n),b(n);
    vpl c,d;
    F0R(i,n){
        cin>>a[i];
    }
    F0R(i,n){
        cin>>b[i];
    }
    F0R(i,n){
        c.pb({a[i]/2,b[i]/2});

        d.pb({a[i]&1,b[i]&1});
    }
    vl ans1;
    if(c.front().fst==0 and c.front().scnd==0){
        ans1.pb(0);
        bool t=check(c,ans1,0,n);
        if(t==false){
            cout<<"NO\n";
            return ;
        }
    }
    else if(c.front().fst==1 and c.front().scnd==1){
        ans1.pb(1);
        bool t=check(c,ans1,1,n);
        if(t==false){
            cout<<"NO\n";
            return ;
        }
    }else if(c.front().fst==0 and c.front().scnd==1){
        cout<<"NO\n";
        return;
    }else{
        ans1.pb(0);
        bool t=check(c,ans1,1,n);
        if(t==false){
            ans1.clear();
            ans1.pb(1);
            t=check(c,ans1,0,n);
            if(t==false){
                cout<<"NO\n";
                return;
            }
        }
    }
    vl ans2;
    if(d.front().fst==0 and d.front().scnd==0){
        ans2.pb(0);
        bool t=check(d,ans2,0,n);
        if(t==false){
            cout<<"NO\n";
            return ;
        }
    }
    else if(d.front().fst==1 and d.front().scnd==1){
        ans2.pb(1);
        bool t=check(d,ans2,1,n);
        if(t==false){
            cout<<"NO\n";
            return ;
        }
    }else if(d.front().fst==0 and d.front().scnd==1){
        cout<<"NO\n";
        return;
    }else{
        ans2.pb(0);
        bool t=check(d,ans2,1,n);
        if(t==false){
            ans2.clear();
            ans2.pb(1);
            t=check(d,ans2,0,n);
            if(t==false){
                cout<<"NO\n";
                return;
            }
        }
    }
    assert(ans1.size()==ans2.size());
    cout<<"YES\n";
    F0R(i,n+1){
        cout<<2*ans1[i]+ans2[i]<<" ";
    }
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;//cin>>t;
    while(t--)sol();
    return 0;
}
