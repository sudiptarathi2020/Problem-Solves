
#include<bits/stdc++.h>
#define ll long long
using pii=std::pair<int,int>;
using namespace std;
struct Node{
    ll x,ymin,ymax;
    bool S;
    Node(ll _x,ll _ymin,ll _ymax,bool _state):x(_x),ymin(_ymin),ymax(_ymax),S(_state){}
};
void sol(int test){
    ll n;cin>>n;
    vector<Node>arr;
    for(int i=0;i<n;i++){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        arr.push_back(Node(x1,y1,y2,false));
        arr.push_back(Node(x2,y1,y2,true));
    }
    sort(arr.begin(),arr.end(),[](Node a,Node b){return a.x<b.x;});
    ll ans=0,tempx;
    multiset<ll>st;
    for(int i=0;i<(int)arr.size();i++){
        if(i){
            ll Min=*st.begin();
            ll Max=*(--st.end());
            ans+=(arr[i].x-tempx)*(Max-Min);
        }
        if(arr[i].S==false){
            st.insert(arr[i].ymin);
            st.insert(arr[i].ymax);
        }else{
            st.erase(st.find(arr[i].ymin));
            st.erase(st.find(arr[i].ymax));
        }
        tempx=arr[i].x;
    }
    cout<<"Case "<<test<<": "<<ans<<endl;
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

