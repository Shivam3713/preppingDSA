class Solution {
public:
    int solve(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(amount  == 0) return 0;
        if(ind  == 0){
            if(amount%coins[ind] == 0) return amount/coins[ind];
            return 1e9;
        }
        if(dp[ind][amount] != -2) return dp[ind][amount];
        int take =1e9;
        if(coins[ind]<=amount){
            take = 1+solve(ind, amount-coins[ind], coins, dp);
        }
        int nottake=  solve(ind-1, amount,coins, dp );
        return dp[ind][amount] = min(take, nottake);

    }
    int coinChange(vector<int>& coins, int amount) { 
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -2));
        // int ans = solve(n-1, amount, coins, dp);
        // if (ans>= 1e9) return -1;
        // return ans;
        // now for the tabulation approach
        vector<vector<int>>dp(n, vector<int>(amount+1, INT_MAX));
        //base case
        for(int i=0;i<n;i++) dp[i][0]= 0
        for(j=1;j<=amount;j++){
            if(j%coins[0] == 0){
                dp[0][j]=j/coins[0];
            }
            else dp[0][j] = 1e9;
        }
        for(int ind = 1;ind<n;ind++){
            for(cur=1;cur<=amount;cur++){
                int take = 1e9
                if(cur>= coins[ind] &&  dp[i - coins[ind]] != INT_MAX){
                    take = 1+dp[ind][cur-coins[ind]]
                }
                int nottake = dp[ind-1][cur];
                dp[ind][cur] = min(take, nottake);
            }
        }
        return dp[n-1][amount] == 1e9? -1: dp[n-1][amount];


    }
};