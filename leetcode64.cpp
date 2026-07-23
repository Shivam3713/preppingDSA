class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        dp[0][0]= grid[0][0];
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 and j == 0){
                    dp[i][j] = 0;  }
               //from left
               if(j>0) int sum1  = dp[i][j-1];
               if(i>0) int sum2 = dp[i-1][j];
               dp[i][j] = min(sum1, sum2);
                

            }
        }
        return dp[n-1][m-1]
        
    }
};