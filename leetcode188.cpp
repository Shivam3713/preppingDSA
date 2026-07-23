class Solution {
private:
    int solve(int ind, int buy, int k, vector<int>&prices, vector<vector<vector<int>>>&dp){
        int n = prices.size();
        if (ind == n || k == 0) return 0;
        
        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];

        if(buy){
            dp[ind][buy][k] = max(-prices[ind]+solve(ind+1, 0, k, prices, dp), solve(ind+1, 1, k, prices, dp));}
        else dp[ind][buy][k] = max(prices[ind]+solve(ind+1, 1, k-1, prices, dp), solve(ind+1, 0, k, prices, dp));


        return dp[ind][buy][k];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return solve(0, 1, k, prices, dp);
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int ind=n-1;ind>=0;ind++){
            for(int buy = 0;buy<=1;buy++){
                for(int cap =0;cap<=k;cap++){
                    if(buy){
                        dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap], dp[ind+1][buy][cap]);
                    }
                    else dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap+1], dp[ind+1][0][cap]);
                }
            }
        }
        return dp[0][1][k];

    }
};