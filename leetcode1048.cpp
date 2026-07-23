#include<bits/stdc++.h>
using namespace std;
Solution {
private:
    bool check(string &a, string &b){
    int n = a.size();
    int m = b.size();
    if(m+1 != n) return false;
    int i=0, j=0;
    while(i<n){
        if(j<m && a[i] == b[j]){
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    if( i== a.size() && j==b.size()) return true;
    else return false;
}
public:
    int longestStrChain(vector<string>& str) {
    int n = str.size();
    sort(str.begin(), str.end(), [](string &a, string &b){
        return a.size()<b.size();
    });

    vector< int>dp(n, 1);
    int maxi =1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(check(str[i], str[j]) && dp[j]+1 >dp[i]){
                dp[i] = 1+dp[j];
                maxi = max(maxi, dp[i]);
            }
        }
    }
    return maxi;
    }
};

int main(){
  Solution sol = new Solution();
  cout<<sol.longestStrChain();
}