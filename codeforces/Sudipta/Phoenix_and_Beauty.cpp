#include<bits/stdc++.h>
#define ll long long
using namespace std;
void sol(){
    ll n;cin>>n;
    ll k;cin>>k;
    vector<ll>v(n);
    set<ll>st;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        st.insert(v[i]);
    }
    if((ll)st.size()>k){
        cout<<"-1\n";return;
    }else{
        ll kk=1;
        while((ll)st.size()!=k){
            st.insert(kk);kk++;
        }
        cout<<(ll)st.size()*n<<endl;
        vector<ll>ans;
        for(ll I:st){
            ans.push_back(I);
        }
        while(n--){
            for(ll I:ans){
                cout<<I<<" ";
            }
        }
        cout<<endl;
       
    }
    

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--)sol();
    return 0;
}
