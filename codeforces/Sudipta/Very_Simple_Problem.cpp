//https://codeforces.com/contest/55/problem/E
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct pt{
    ll x,y;
    pt(){}
    pt(ll _x,ll _y):x(_x),y(_y){}
    pt operator+(const pt &p)const{return pt(x+p.x,y+p.y);}
    pt operator-(const pt &p)const{return pt(x-p.x,y-p.y);}
    ll cross(const pt &p)const{return x*p.y-y*p.x;}
    ll dot(const pt &p)const{return x*p.x+y*p.y;}
    ll cross(const pt &a,const pt &b)const{return (a-*this).cross(b-*this);}
    ll dot(const pt &a,const pt &b)const{return (a-*this).dot(b-*this);}
    ll LEN()const {return this->dot(*this);}
};
bool LexComp(const pt &l,const pt &r){
    return l.x<r.x||(l.x==r.x && l.y<r.y);
}
int sgn(long long val){
    return val>0?1:val==0?0:-1;
}
vector<pt>seq;
pt translation;
ll n;
bool point_in_triangle(pt a,pt b,pt c,pt point){
    ll s1=abs(a.cross(b,c));
    ll s2=abs(point.cross(a,b));
    ll s3=abs(point.cross(b,c));
    ll s4=abs(point.cross(c,a));
    return s1==(s2+s3+s4);
}
void prepare(vector<pt>&points){
    n=(ll)points.size();
    ll pos=(ll)0;
    for(ll i=1;i<n;i++)
        if(LexComp(points[i],points[pos]))
            pos=i;
    rotate(points.begin(),points.begin()+pos,points.end());
    n--;seq.resize(n);
    for(ll i=0;i<n;i++)
        seq[i]=points[i+1]-points.front();
    translation=points.front();
}
bool point_in_polygon(pt point){
    point=point-translation;
    if(seq.front().cross(point)!=0 and sgn(seq.front().cross(point))!=sgn(seq.front().cross(seq.back())))return false;
    if(seq.back().cross(point)!=0 and sgn(seq.back().cross(point))!=sgn(seq.back().cross(seq.front())))return false;
    if(seq.front().cross(point)==0){
        return seq.front().LEN()>=point.LEN();
    }
    ll l=0,r=n-1;
    while(r-l>1){
        ll mid=(r+l)>>1;
        if(seq[mid].cross(point)>=0)
            l=mid;
        else
            r=mid;
    }
    return point_in_triangle(seq[l],seq[l+1],pt(0,0),point);
}
int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}
bool cw(pt a, pt b, pt c, bool include_collinear=false) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll nn;cin>>nn;
    vector<pt>arr(nn);
    for(ll i=0;i<nn;i++)cin>>arr[i].x>>arr[i].y;
    vector<pt>brr=arr;
    reverse(brr.begin(),brr.end());
    prepare(brr);
    ll q;cin>>q;
    ll P=nn*(nn-1)*(nn-2)/6;
    while(q--){
        pt a;cin>>a.x>>a.y;
        if(!point_in_polygon(a)){
            cout<<0<<endl;
            continue;
        }
        ll Z=P;
        for(ll i=0;i<nn;i++){
            ll low=1,high=nn-1;
            while(high>low){
                ll mid=(high+low)>>1;
                ll kid=(mid+i)%nn;
                if(orientation(arr[i],a,arr[kid])==-1){
                    high=mid-1;
                }else{
                    low=mid;
                }
                if(high==low+1){
                    if(orientation(arr[i],a,arr[(high+i)%nn])==1){
                        low=high;
                    }
                    break;
                }
            }
            Z-=(low)*(low-1)/2;
        }
        if(Z<0)Z=0;
        cout<<Z<<endl;
    }
}
