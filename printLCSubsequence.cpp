class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        // vector<int>curr(m+1, 0), prev(m+1, 0);
        //base case already covered since i filled row0 and col 0 as 0;
        string res ="";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j]= 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
            
        }
        int i=n, j=m;
        while(i>0 && j>0){
            if(text1[i-1] == text2[j-1]){
                res+=text1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }
                else j--;
            }

        }
        reverse(res.begin(), res.end());
        cout<<res<"\n";
        return 0;
        // return dp[n][m];
        // return prev[m];
    }
};