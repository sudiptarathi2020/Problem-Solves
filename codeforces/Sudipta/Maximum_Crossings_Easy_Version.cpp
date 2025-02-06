#include<bits/stdc++.h>
using namespace std;
struct segtree{
    struct node
    {
        int st,ed;
        int mn;
        node *l,*r;
        node(){}
        node(int _x, int _y){
            st=_x,ed=_y;
            l=r=NULL; mn = 0;
        }
    };
    node *Node;
    segtree(){}
    segtree(int n){
        Node=new node(0,n-1);
    }
    void build(node *ob ,vector<int>&v)
    {

        if(ob->st==ob->ed)
        {
            int ind = ob->st;
            ob->mn = v[ob->st];
            return ;
        }
        int mid = (ob->st + ob->ed)/2;
        if(ob->l==NULL)ob->l = new node(ob->st, mid);
        if(ob->r==NULL)ob->r = new node (mid+1, ob->ed);

            build(ob->l,v);
            build(ob->r,v);

        ob->mn = ( ob->l->mn+ ob->r->mn);


    }


    long long query(node *ob , int x , int y)
    {

        if(ob->st==x && ob->ed==y)
        {
            return ob->mn;
        }
        int mid = (ob->st + ob->ed)/2;

        if(y<=mid)
        {
            return query(ob->l,x,y);
        }

        else if(x>mid)
        {
            return query(ob->r,x,y);
        }
        {
            int a = query(ob->l, x, mid);
            int b = query(ob->r, mid+1, y);
            return (a+b);
        }
    }
    void update(node *ob , int x , int y, int  k)
    {


        if(x>ob->ed||y<ob->st){
            return;
        }
        if(x==ob->st && y==ob->ed){
            ob->mn=k;
            return;
        }
        int mid=(ob->st+ob->ed)/2;
        if(y<=mid){
            update(ob->l,x,y,k);
        }else if(x>mid){
            update(ob->r,x,y,k);
        }else{
            update(ob->l,x,mid,k);
            update(ob->r,mid+1,y,k);
        }
        ob->mn=(ob->l->mn+ob->r->mn);
    }
    void create(vector<int>&v){

        build(Node,v);
    }
    int query(int a,int b){
        return query(Node,a,b);
    }
    void update(int a,int b,int c){
        update(Node,a,b,c);
    }
};
void sol()
{
    int n;cin>>n;
    vector<int>v(n+1,0);
    vector<int>ans(n+1);
    for(int i=1;i<=n;i++){
        cin>>ans[i];
        v[ans[i]]++;
    }
    segtree seg(n+1);
    seg.create(v);
    int ans1=0;
    for(int i=1;i<=n;i++){
        ans1+=seg.query(0,ans[i]);
        ans1--;
        seg.update(ans[i],ans[i],seg.query(ans[i],ans[i])-1);
    }
    cout<<ans1<<endl;
    return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;cin>>n;
    while(n--)sol();
    return 0;
}
