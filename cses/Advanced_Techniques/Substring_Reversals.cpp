#include<bits/stdc++.h>
using namespace std;
using pt =struct node*;
struct node{
    int priority,sz;
    pair<int,char>val;
    bool lazy=0;
    pt child[2];
    node(pair<int,char> _val){
        priority=rand();
        val=_val;sz=1;
        child[0]=child[1]=NULL;
    }
    ~node(){
        for(int i:{0,1}){
            delete(child[i]);
        }
    }
};
int getsz(pt x){
    return x?x->sz:0;
}
pt propagate(pt x){
    if(!x or !x->lazy)return x;
    swap(x->child[0],x->child[1]);
    x->lazy=0;
    for(int i:{0,1}){
        if(x->child[i]){
            x->child[i]->lazy^=1;
        }
    }
    return x;
}
pt calculate(pt x){
    pt a=x->child[0],b=x->child[1];
    assert(!x->lazy);
    propagate(a),propagate(b);
    x->sz=1+getsz(a)+getsz(b);
    return x;
}
void traverse(pt x,vector<pair<int,char>>&tour){
    if(!x)return;
    propagate(x);
    traverse(x->child[0],tour);
    tour.push_back(x->val);
    traverse(x->child[1],tour);
}
pair<pt,pt> split(pt t,pair<int,char> v){
    if(!t)return {t,t};
    propagate(t);
    if(t->val>=v){
        pair<pt,pt>p=split(t->child[0],v);
        t->child[0]=p.second;
        return {p.first,calculate(t)};
    }else{
        pair<pt,pt>p=split(t->child[1],v);
        t->child[1]=p.first;
        return {calculate(t),p.second};
    }
}
pair<pt,pt> splitsz(pt t,int sz){
    if(!t)return {t,t};
    propagate(t);
    if(getsz(t->child[0])>=sz){
        pair<pt,pt>p=splitsz(t->child[0],sz);
        t->child[0]=p.second;
        return {p.first,calculate(t)};
    }else{
        pair<pt,pt>p=splitsz(t->child[1],sz-getsz(t->child[0])-1);
        t->child[1]=p.first;
        return {calculate(t),p.second};
    }
}
pt merge(pt L,pt R){
    if(!L)return R;
    if(!R)return L;
    propagate(L),propagate(R);
    pt T;
    if(L->priority>R->priority){
        L->child[1]=merge(L->child[1],R);
        T=L;
    }else{
        R->child[0]=merge(L,R->child[0]);
        T=R;
    }
    return calculate(T);
}
pt insert(pt x,pair<int,char>v){
    pair<pt,pt>a=split(x,v);
    pair<pt,pt>b=split(a.second,{v.first+1,v.second});
    return merge(a.first,merge(new node(v),b.second));
}
pt remove(pt x,pair<int,char>v){
    pair<pt,pt>a=split(x,v);
    pair<pt,pt>b=split(a.second,{v.first+1,v.second});
    return merge(a.first,b.second);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;cin>>n>>m;
    string s;cin>>s;
    pt root=new node({0,s[0]});
    for(int i=1;i<(int)s.size();i++){
        pt N=new node({i,s[i]});
        root=merge(root,N);
    }
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        pair<pt,pt>p1=splitsz(root,x-1);
        pair<pt,pt>p2=splitsz(p1.second,y-x+1);
        p2.first->lazy^=1;
        root=merge(p1.first,p2.first);
        root=merge(root,p2.second);
    }
    vector<pair<int,char>>tour;
    traverse(root,tour);
    for(auto x:tour){
        cout<<x.second;
    }
    cout<<endl;
}
