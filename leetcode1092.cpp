class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        string res ="";
        for(int i =1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // return dp[n][m];

        int i=n, j=m;
        while(i>=0 && j>=0){
            if(str1[i-1] == str2[j-1]){
                res+=str1[i-1];
            }
            else{
                if( dp[i-1][j] > dp[i][j-1]){
                    i-=1;
                    res+=str1[i-1];
                }
                else{
                    j-=1;
                    res+=str2[j-1];
                }
            }
        }
        while(i>0){
            res+=str1[i-1];
            i-=1;
        }
        while(j>0){
            res+str2[j-1];
            j-=1;
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};