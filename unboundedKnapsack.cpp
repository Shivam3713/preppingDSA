#include <bits/stdc++.h>
using namespace std;

// Driver code
int main() {
    // Initialize item weights
    vector<int> wt = {2, 4, 6};

    // Initialize item values
    vector<int> val = {5, 11, 13};

    // Weight capacity of the knapsack
    int W = 10;
    

    int n = wt.size();
    if(n ==0) return 0;
    vector<vector<int>>dp(n, vector<int>(W+1, 0));
    
    //base case
    for(int i=0;i<=W;i++){
        if(wt[0]<=i){
             dp[0][i] = (i/wt[0])*val[0]
        }
       
    }
    for(int ind=1;ind<n;ind++){
        for(int w=1;w<=W;w++){
            int nottake = 0+dp[ind-1][w];
            int take=INT_MIN
            if(wt[ind]<=w){
                take = val[ind]+dp[ind][w-wt[ind]]
            }
            dp[ind][w]= max(take, nottake);

        }
    }


   
    return 0;
}
