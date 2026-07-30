#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={10, 15, 20, 25};
    int n = arr.size();
    vector<vector<int>>dp(n, vector<int>(n, 0));
    //since tabulation we dont need to write where there is only a single matrix i==j return 0
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int total = INT_MAX;
            for(int k=i;k<j;k++){
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                total= min(total, cost1+cost2+(arr[i-1]*arr[k]*arr[j]));
            }
            dp[i][j]= total;

        }
    }
    cout<<dp[1][n-1];

}