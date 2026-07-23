class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2, 0));
        dp[0][0]=0 ,dp[0][1]=INT_MIN;
        for(int i=1;i<=n;i++){
                //at j =0 means that now we dont have a stock in hadn, and our optsion are to stay stockless or buy
                //at j=1 means that we have bought a stock in hand, and our options are to either sell it or stay with the stock in hand
                dp[i][0] = max(prices[i-1]+dp[i-1][1], dp[i-1][0]);
                dp[i][1]=max(-prices[i-1]+dp[i-1][0], dp[i-1][1]);
        }
        return dp[n][0];

    }
};