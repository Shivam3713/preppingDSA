
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // we need to find subsets with difference as target
        // the question goes like , find numbers of subsets with sum as (total-target)/2
        // because 
        // s1+s2 = total, s1-s2 = target
        // s1= target+s2
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum - target < 0) return 0;
        if ((sum - target) % 2 != 0) return 0;
        int tot = (sum - target) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(tot + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= tot; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][tot];
    }
};  