#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> prices = {2, 4, 6, 8};
    int n = prices.size();
    vector<int>dp(n+1, 0)
    int maxi = INT_MIN;
    for(int len=1;len<=n;len++){
        for(int cut=1;cut<=len;cut++){
            dp[len]= max(dp[len], prices[cut-1]+dp[len-cut]);
        }

    }
    return dp[n];   
}
