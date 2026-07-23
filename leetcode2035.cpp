class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        //using the idea of equal sum partition
        //let's write the tabulation for it and then since our result is hiddden in the last row of the tabulation row
        int totSum = 0;
        int n = nums.size();
        if(n == 0) return 0;
        for(int i=0;i<n;i++) totSum+=nums[i];
        int sum= totSum/2;
        vector<vector<int>>dp(n, vector<int>(sum+1, 0));
        for(int i=0;i<n;i++){
            dp[i][0]= true;
        }
        if (nums[0] <= sum) dp[0][nums[0]]= true; 
        for (int ind = 1;ind<n;ind++){
            for(int target = 1;target<sum+1;target++){
                bool take = false;
                bool nottake = dp[ind-1][target];
                if(target-nums[ind]>=0){
                    take = dp[ind-1][target-nums[ind]];
                }
                dp[ind][target] = take || nottake;
            }
        }

        int mini = INT_MAX;
        for(int i=0;i<sum+1;i++){
            if(dp[n-1][i] == true){
                int s1=i;
                mini = min(mini, abs(totSum-(s1*2)));
            }
        }
        return mini;
        
    }
};