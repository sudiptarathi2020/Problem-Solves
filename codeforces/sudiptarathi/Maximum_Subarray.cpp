//https://codeforces.com/problemset/problem/1796/D
#include<bits/stdc++.h>
using namespace std;
struct Data {
    long long sum, pref, suff, ans;
    Data(){}
};
struct SEG{
    vector<Data>t;
    SEG(){}
    SEG(long long n){
        t.resize(4*n);
    }
    Data combine(struct Data l,struct Data r) {
        Data res;
        res.sum = l.sum + r.sum;
        res.pref = max(l.pref, l.sum + r.pref);
        res.suff = max(r.suff, r.sum + l.suff);
        res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
        return res;
    }
    Data make_Data(long long val) {
        Data res;
        res.sum = val;
        res.pref = res.suff = res.ans = max(0ll, val);
        return res;
    }
    void build(long long a[], long long v, long long tl, long long tr) {
        if (tl == tr) {
            t[v] = make_Data(a[tl]);
        } else {
            long long tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    void update(long long v, long long tl, long long tr, long long pos, long long new_val) {
        if (tl == tr) {
            t[v] = make_Data(new_val);
        } else {
            long long tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }
    Data query(long long v, long long tl, long long tr, long long l, long long r) {
        if (l > r) 
            return make_Data(0);
        if (l == tl && r == tr) 
            return t[v];
        long long tm = (tl + tr) / 2;
        return combine(query(v*2, tl, tm, l, min(r, tm)), 
                query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
};
int  main(){
    long long t;cin>>t;
#define ll long long
    while(t--){
		long long n;cin>>n;
		SEG S(n);
		long long k,x;cin>>k>>x;
		long long arr[n],brr[n];
		for(ll i=0;i<n;i++){
			cin>>arr[i];
            brr[i]=arr[i]-x;
		}
		S.build(brr,1,0,n-1);
		long long MX=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<k;j++){
                S.update(1,0,n-1,(i+j)%n,arr[(i+j)%n]+x);
            }
            MX=max(MX,S.query(1,0,n-1,0,n-1).ans);
            for(int j=0;j<k;j++){
                S.update(1,0,n-1,(i+j)%n,arr[(i+j)%n]-x);
            }
        }
		cout<<MX<<endl;
    }
}
