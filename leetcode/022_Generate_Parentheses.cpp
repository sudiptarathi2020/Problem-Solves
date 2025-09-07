#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string>ans;
            string exp;
            for(int i=0;i<n;i++){
                exp.push_back('(');
            }
            for(int i=0;i<n;i++){
                exp.push_back(')');
            }
            while(1){
                stack<int>stk;
                for(char x:exp){
                    if(stk.empty()){
                        stk.push(x);
                    }else{
                        if(x=='('){
                            stk.push(x);
                        }else{
                            if(stk.top()=='('){
                                stk.pop();
                            }
                        }
                    }
                }
                if(stk.empty()){
                    ans.push_back(exp);
                }
                if(!next_permutation(exp.begin(),exp.end())){
                    break;
                }
            }
            return ans;
        }

};
int main(){
    Solution sol;
    vector<string>ans = sol.generateParenthesis(3);
    for(string x:ans){
        cout<<x<<endl;
    }
}
