class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        //if word 2 is empty
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        // if word1 is empty
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    //if the character matches then decrease both i and j
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    //insert means j will decrease by 1 and plus 1 operation
                    //replace means i and j both with decrease  by 1 and plus 1 operation
                    //delete means i will decrease by 1 and plus 1 operation
                    dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));

                }
            }
        }
        return dp[n][m];

        
    }
};