#include<bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<int>&arr, vector<vector<int>>&dp){
    //base case, that if there is only one single matrix then return 0
    if(i == j) return 0;
    //if already computed return 
    if(dp[i][j]!= -1)return dp[i][j];
    int total = INT_MAX;
    for(int k=i;k<j;k++){
        int cost1 = solve(i, k, arr, dp);
        int cost2 = solve(k+1, j, arr, dp);
        total= min(total, cost1+cost2+(arr[i-1]*[arr[k]*arr[j]]));
    }
    return dp[i][j] = total;
}
int main(){
    vector<int> arr = {40, 20, 30, 10, 30};
    int n = arr.size();
    vector<vector<int>>dp(n, vector<int>(n, -1));
    int ans = solve(1, n-1, arr, dp);
    cout<<ans;

}