class Solution {
public:
    int minInsertions(string s) {
        //in this ans would be len of string - len of longest palindromic subsequence;

        string s1 = s;
        reverse(s1.begin(), s1.end());
        int n  s.size();
        vector<int>prev(n+1, 0), curr(n+1, 0);
        for(int i =1;i<=n;i++){
            for(int j =1;j<=n;j++){
                if(s1[i-1] == s[j-1]){
                    curr[j]= 1+prev[j-1];
                }
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return n-prev[n];
    }
};