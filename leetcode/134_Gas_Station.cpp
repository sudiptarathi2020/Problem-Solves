#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            size_t N = gas.size();
            for(size_t i = 0; i<N;i++){
                cost.push_back(cost[i]);
                gas.push_back(gas[i]);
            }
            int total_gas = 0;
            list<pair<int,pair<int,int>>>lst;
            for(size_t i = 0;i<2*N;i++){
                if(lst.size()){
                    if(gas[i]+total_gas>=cost[i]){
                        lst.push_back(make_pair(i,make_pair(gas[i],cost[i])));
                        total_gas +=(gas[i]-cost[i]);
                    }else{
                        while(lst.size() && gas[i]+total_gas<cost[i]){
                            auto [idx,_cost] = lst.front();
                            lst.pop_front();
                            total_gas +=(_cost.second-_cost.first);
                        }
                        if(gas[i]+total_gas >= cost[i]){
                            lst.push_back(make_pair(i,make_pair(gas[i],cost[i])));
                            total_gas = (gas[i]-cost[i]);
                        }
                    }

                }else{
                    if(gas[i]>=cost[i]){
                        lst.push_back(make_pair(i,make_pair(gas[i],cost[i])));
                        total_gas = (gas[i]-cost[i]);
                    }
                }

                if(lst.size() == N){
                    return lst.front().first;
                }else if(lst.size() == 0){
                    total_gas = 0;
                }

            }
            return -1;
        }
};
int main(){
    class Solution sol;
    vector<int> gas = {5,1,2,3,4};
    vector<int> cost = {4,4,1,5,1};
    cout<<sol.canCompleteCircuit(gas,cost)<<endl;
}
