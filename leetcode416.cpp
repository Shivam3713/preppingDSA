class Solution {
public:
    bool solve(int target, vector<int>&nums, int ind, vector<vector<int>>&dp){
        if(dp[ind][target] != -1) return dp[ind][target];
        if (target == 0 || target- nums[ind] == 0){
            dp[ind][target]= true;
            return dp[ind][target];
        }
        bool take = false, nottake = false;
        if(target-nums[ind]>=0 && ind>0){
             take = solve(target-nums[ind], nums, ind-1, dp);
        }
        if(ind>0) nottake = solve(target, nums, ind-1, dp);
        return dp[ind][target]= take || nottake;
        // return dp[target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2 != 0) return false;
        // else{
        //     //since part1+part2 == sum and both parts must be equal then we can say part1 should be equal to sum/2
        //     int target = sum/2;
        //     vector<vector<int>>dp(n, vector<int>(target+1, -1));
        //     return solve(target, nums, n-1, dp);

        // }
        else{
            int totSum = sum/2;
            vector<vector<int>>dp(n, vector<int>(totSum+1, 0));
            for(int i=0;i<n;i++){
                dp[i][0]= true;
            }
            if (nums[0] == totsum) dp[0][nums[0]]= true;
            for (int ind = 1;ind<n;ind++){
                for(int target = 1;target<totSum+1;target++){
                    bool take = false;
                    bool nottake = dp[ind-1][target];
                    if(target-nums[ind]>=0){
                        take = dp[ind-1][target-nums[ind]];
                    }
                    dp[ind][target] = take || nottake;
                }
            }
            return dp[n-1][totSum];
            

        }
    }
};