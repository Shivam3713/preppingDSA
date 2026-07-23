class Solution {
public:
    int minimumTotal(vector<vector<int>>& shape) {
        int n = shape.size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            int m = shape[0].size();
            for(int j=0;j<m;j++){
                if(j>i) continue;
                if(j == 0){ //only up
                   dp[i][j] = shape[i][j]+dp[i-1][j];
                }
                //diagonal
                else if ( i== j) dp[i][j] = shape[i][j]+dp[i-1][j-1];
                else{
                    dp[i][j] = shape[i][j]+min(dp[i-1][j-1], dp[i-1][j]);
                }
                

            }

        }
        int ans= INT_MAX;
        for(int i=0;i<m;i++){
            ans = mini(ans, dp[n-1][i])
        }
        return ans;
        
    }
};