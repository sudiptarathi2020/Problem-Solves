
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define mkp make_pair
#define endl '\n'
#define ub upper_bound
#define lb lower_bound
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
const ll N=2e5+10;
struct BIT {
    vector<int> bit;  // binary indexed tree
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
void sol(int test){
    ll n,q;cin>>n>>q;
    BIT bit(N);
    BIT tit(N);
    F0R(i,n){
        ll a;cin>>a;
        bit.add(i,1);
        tit.add(i,a);
    }
    cout<<"Case "<<test<<": "<<endl;
    while(q--){
        char x;ll a;cin>>x>>a;
        if(x=='a'){
            bit.add(n,1);
            tit.add(n,a);
            n++;
        }else{
            ll left=0,right=n-1;
            ll ans=-1;
            while(left<=right){
                ll mid=(left+right)>>1;
                if(bit.sum(mid)==a){
                    ans=mid;break;
                }else if(bit.sum(mid)>a){
                    right=mid;
                }else{
                    left=mid+1;
                }
            }
            if(ans==-1){
                cout<<"none\n";continue;
            }
            while(bit.sum(ans,ans)==0){
                ans--;
            }
            cout<<tit.sum(ans,ans)<<endl;
            bit.add(ans,-1);
        
        }
    }
    return; 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int test;cin>>test;
    for(int i=1;i<=test;i++){
        sol(i);
    }
    return 0;
}

