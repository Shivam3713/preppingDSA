#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int ind, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if (ind >= n) return 0;
        if (dp[ind] != -1) return dp[ind];

        int take = nums[ind] + solve(ind + 2, nums, dp);
        int nottake = solve(ind + 1, nums, dp);

        dp[ind] = max(take, nottake);
        return dp[ind];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memoi(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {
            int take = nums[i] + memoi[i + 2];
            int nottake = memoi[i + 1];
            memoi[i] = max(take, nottake);
        }

        return memoi[0];
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution s;
    cout << s.rob(nums) << endl;

    return 0;
}