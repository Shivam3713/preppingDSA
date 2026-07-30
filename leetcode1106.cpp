#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    char solve(vector<char>&values, char op){
       if(op == '!') return values[0] == 't'? 'f':'t';

       //now need to check if op is &
       if(op == '&'){
        return any_of(begin(values), end(values), [](char ch){return ch == 'f';})?'f':'t';
       }
       if(op == '|'){
        return any_of(begin(values), end(values), [](char ch){ return ch =='t';})? 't':'f';
       }
       return 't';
    }
public:
    bool parseBoolExpr(string s) {
        int n = s.size();
        stack<char>st;
        
        for(int i =0;i<n;i++){
            if(s[i] == ',') continue;
            if(s[i] == ')'){
                vector<char>values;
                while(st.top()!= '('){
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                st.push(solve(values, op));
            }
            else st.push(s[i]);
        }
        return st.top() == 't'? true: false;
    }
};
int main(){
    string expression = "&(|(f))";
    Solution* sol = new Solution();
    cout<<sol->parseBoolExpr(expression);
}