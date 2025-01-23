#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Vertex {
    Vertex *l, *r;
    ll sum;
    Vertex(ll val) : l(NULL), r(NULL), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};
Vertex* build(ll a[], ll tl, ll tr) {
    if (tl == tr)
        return new Vertex(a[tl]);
    ll tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}
 
ll get_sum(Vertex* v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    ll tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}
 
Vertex* update(Vertex* v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr)
        return new Vertex(new_val);
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,q;cin>>n>>q;
    ll arr[n];for(ll &x:arr)cin>>x;
    vector<Vertex*>temp;
    temp.push_back(build(arr,0,n-1));
    while(q--){
        ll choice;cin>>choice;
        if(choice==1){
            ll k,a;ll x;cin>>k>>a>>x;
            k--,a--;
            temp[k]=update(temp[k],0,n-1,a,x);
        }else if(choice==2){
            ll k,a,b;cin>>k>>a>>b;
            k--,a--,b--;
            cout<<get_sum(temp[k],0,n-1,a,b)<<endl;
        }else{
            ll k;cin>>k;k--;
            temp.push_back(temp[k]);
        }
    }
    return 0;
}
