class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        // vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        vector<int>curr(m+1, 0), prev(m+1, 0);
        //base case already covered since i filled row0 and col 0 as 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    curr[j]= 1+ prev[j-1];
                }
                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev= curr;
        }
        // return dp[n][m];
        return prev[m];
    }
};