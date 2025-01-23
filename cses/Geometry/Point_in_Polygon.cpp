#include<bits/stdc++.h>
using namespace std;
struct pt {
    long long x, y;
    pt() {}
    pt(long long _x, long long _y) : x(_x), y(_y) {}
    pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt& p) const { return x * p.y - y * p.x; }
    long long cross(const pt& a, const pt& b) const { return (a - *this).cross(b - *this); }
};
pt K(1e9+17,1e9+7);
long long sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }
 
bool inter1(long long a, long long b, long long c, long long d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}
 
bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
    if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
           sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}
long long dist(pt a,pt b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main(){
    long long n,m;cin>>n>>m;
    pt a[n];
    for(long long i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    while(m--){
        pt pivot;cin>>pivot.x>>pivot.y;
        bool boun=false;
        for(long long i=0;i<n;i++){
            if(pivot.cross(a[i],a[(i+1)%n])==0 and dist(a[i],a[(i+1)%n])>=(dist(a[i],pivot)+dist(a[(i+1)%n],pivot))){
                boun=true;
                break;
            }
        }
        if(boun){
            cout<<"BOUNDARY\n";
            continue;
        }
        long long ans=0;
        for(long long i=0;i<n;i++){
            if(check_inter(pivot,K,a[i],a[(i+1)%n])){
                ans++;
            }
        }
        if(ans&1){
            cout<<"INSIDE\n";
        }else{
            cout<<"OUTSIDE\n";
        }
    }
}
