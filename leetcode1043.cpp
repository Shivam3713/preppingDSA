#include<bits/stdc++.h>
using namespace std;
class Solution {
private: int solve(int ind, vector<int>&arr, int k, vector<int>dp){
    if(ind>=arr.size())return 0;
    int res=INT_MIN, maxEle = INT_MIN;
    if(dp[ind]!= -1)return dp[ind];
    for(int j=ind;j<ind+k && j<arr.size();j++){
        maxEle = max(maxEle, arr[j]);
        int curr= (maxEle*(j-ind+1))+solve(j+1, arr, k, dp);
        res = max(res, curr);
    }
    return dp[ind]=res;
}
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(), -1);
        int ans = solve(0, arr, k, dp);
        return ans;
    }
};

int main(){
    Solution* s = new Solution();
    cout<<s->maxSumAfterPartitioning(vector<int>arr ={1, 15, 7, 9, 2, 5, 10}, 3);
}