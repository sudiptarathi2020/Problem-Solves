
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
const int N=510;
int t[N<<2][N<<2];
int a[N][N];
int n,m;;
int op(int a,int b){
    return max(a,b);
}
void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = op(t[vx*2][vy] , t[vx*2+1][vy]);
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = op(t[vx][vy*2] , t[vx][vy*2+1]);
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 1, m);
}
int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) 
        return INT_MIN;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return op(sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy))
         , sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry));
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return INT_MIN;
    if (lx == tlx && trx == rx)
        return sum_y(vx, 1, 1, m, ly, ry);
    int tmx = (tlx + trx) / 2;
    return op(sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry)
         , sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry));
}
void sol(int test){
    int q;
    cin>>n>>q;;
    m=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    build_x(1,1,n);
    cout<<"Case "<<test<<":\n";
    while(q--){
        int a,b,s;cin>>a>>b>>s;
        int c=a+s-1;
        int d=b+s-1;
        cout<<sum_x(1,1,n,a,c,b,d)<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        sol(i);
    }
    return 0;
}

