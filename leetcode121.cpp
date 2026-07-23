class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini= INT_MAX, maxprofit = INT_MIN;
        for(int i=0;i<prices.size();i++){
            if(prices[i] < mini)mini = prices[i];
            int cost = prices[i]-mini;
            maxprofit = max(maxprofit, cost);
        }
        return maxprofit;
        
    }
};