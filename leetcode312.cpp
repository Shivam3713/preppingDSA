// #include<bits/stdc++.h>
// using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //since it said if index goes out of bound think of it as ballon with  paint 1 so insert 1 in both ends, that is , insert 1 in left and insert 1 in right, this does not need sort
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int left = n-1;left>=0;left--){
            for(int right = left+2;right<n;right++){
                int cost = INT_MIN;
                for(int k=left+1;k<right;k++){
                    cost= max(cost, nums[left]*nums[k]*nums[right]+dp[left][k]+dp[k][right]);
                }
                dp[left][right]=cost;
            }
        }
        return dp[0][n-1];
    }
};
// int main(){
//     vector<int>nums ={3,1,5,8};
//     Solution* sol = new Solution();
//     cout<<sol->maxCoins(nums);
// }