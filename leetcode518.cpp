class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (coins.empty()) return amount == 0 ? 1 : 0;
        int n = coins.size();
        // vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        vector<int>prev(amount+1, 0);
        if(amount == 0) return 1;
        for(int i=0;i<=amount;i++) if(i%coins[0]==0) prev[i] = 1;
        for(int ind=1;ind<n;ind++){
        vector<int>curr(amount+1, 0);
            for(int target  = 0;target<=amount;target++){
                int take =0;
                int nottake = prev[target];
                if(coins[ind]<=target){
                        take=curr[target-coins[ind]]; // stay in the same index and 
                    }
                    curr[target]= take+nottake;
                }
                prev = curr;

            }
            return prev[amount];
        }
};