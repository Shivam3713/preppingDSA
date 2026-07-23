class Solution {
private: 
    bool isAllStars(string &p, int j){
    for(int k = 0; k < j; k++){
        if(p[k] != '*') return false;
    }
    return true;
    }

public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>>dp(n+1, vector<bool>(m+1, false));

        // if pattern gets exhausted
        for(int i=0;i<=n;i++){
        dp[i][0]=false;
        }

        //if string gets exhausted but what if in pattern there is '*' existing so for that also we need to check
        for (int i = 1; i <= m; i++) {
            dp[0][i] = isAllStars(p, i);
        }
        dp[0][0]=true;
        

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?') dp[i][j]= dp[i-1][j-1];
                else{
                    if(p[j-1] == '*'){
                       //yaha pe hum try karenge ki agar * ek character to check karna hai toh hum j-1 kardenge
                       //aur agar sure nahi hai ki aage bhi string mein unmatched aayenge toh i-1 kardenge
                       dp[i][j] = dp[i-1][j]||dp[i][j-1];
                    }
                }
            }
        }
        return dp[n][m];
    }
};