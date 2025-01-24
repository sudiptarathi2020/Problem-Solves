
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
struct seg{
    int start,end,sum=0,lazy=0;
    seg *start_child=nullptr,*end_child=nullptr;
    seg(int Left,int Right){
        start=Left,end=Right;
    }
    void extend(){
        if(!start_child and start!=end){
            int mid=(start+end)>>1;
            start_child=new seg(start,mid);
            end_child=new seg(mid+1,end);
        }
    }
    void propagate(){
        sum+=(end-start+1)*lazy;
        if(start!=end){
            start_child->lazy+=lazy;
            end_child->lazy+=lazy;
        }
        lazy=0;
    }
    void upd(int Left,int Right,int val){
        extend();
        propagate();
        if(Left==start and Right==end){
            sum+=(end-start+1)*val;
            if(start!=end){
                start_child->lazy+=val;
                end_child->lazy+=val;
            }
            return;
        }
        int mid=(start+end)>>1;
        if(Right<=mid){
            start_child->upd(Left,Right,val);
        }else if(mid<Left){
            end_child->upd(Left,Right,val);
        }else{
            start_child->upd(Left,mid,val);
            end_child->upd(mid+1,Right,val);
        }
        sum=start_child->sum+end_child->sum;
    }
    int get(int Left,int Right){
        extend();
        propagate();
        if(start==Left and end==Right){
            return sum;
        }
        int mid=(start+end)>>1;
        if(Right<=mid){
            return start_child->get(Left,Right);
        }else if(mid<Left){
            return end_child->get(Left,Right);
        }else{
            return start_child->get(Left,mid)+end_child->get(mid+1,Right);
        }
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    for(int test_case=1;test_case<=t;test_case++){
        int n,q;cin>>n>>q;
        //seg *S=new seg(0,100);
        vector<int>arr;
        vector<pair<int,int>>updates;
        vector<int>queries;
        for(int i=0;i<n;i++){
            int a,b;cin>>a>>b;
            arr.push_back(a);
            arr.push_back(b);
            updates.push_back({a,b});
        }
        for(int i=0;i<q;i++){
            int a;cin>>a;
            arr.push_back(a);
            queries.push_back(a);
        }
        sort(arr.begin(),arr.end());
        vector<int>brr;
        size_t i=0;
        while(i<arr.size()){
            brr.push_back(arr[i]);
            size_t j=i;
            while(j<arr.size()){
                if(arr[i]==arr[j]){
                    j++;
                }else{
                    break;
                }
            }
            i=j;
        }
        unordered_map<int,int>mp;
        for(size_t i=0;i<brr.size();i++){
            mp[brr[i]]=i;
        }
        seg *S=new seg(0,mp[brr.back()]+1);
        for(auto x:updates){
            S->upd(mp[x.first],mp[x.second],1);
        }
        cout<<"Case "<<test_case<<": \n";
        for(int x:queries){
            cout<<S->get(mp[x],mp[x])<<endl;
        }

    }
}
