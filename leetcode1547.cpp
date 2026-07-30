#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int solve(int left, int right, vector<int>&cuts, vector<vector<int>>&dp){
        if(right-left <=1)return 0;
        if(dp[left][right] != -1)return dp[left][right];
        int cost= INT_MAX;
        for(int k=left+1;k<right;k++){
             cost = min(cost, cuts[right]-cuts[left]+solve(left, k, cuts, dp)+solve(k, right, cuts, dp));
        }
        return dp[left][right] = cost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        // vector<vector<int>>dp(m, vector<int>(m, -1));
        // int ans = solve(0, cuts.size()-1, cuts, dp);
        // cout<<ans;
        // return ans;
        vector<vector<int>>dp(m, vector<int>(m, 0));
        for(int i=0;i<m-1;i++)dp[i][i+1] =0; //this is the base case since j-i <=1 becomes zero as there wont be any len to cut since len of stick is on

        for(int left = m-1;left>=0;left--){
            for(int right = left+2;right<m;right++){
                int cost= INT_MAX;
                for(int k=left+1;k<right;k++){
                    cost = min(cost, cuts[right]-cuts[left]+dp[left][k]+dp[k][right]);
                }
                dp[left][right] = cost;
            }
        }
        return dp[0][m-1];
}};
int main(){
    Solution* s = new Solution();
    int n=7;
    vector<int>arr={1,3,4,5};
    cout<<s->minCost(n, arr);
}