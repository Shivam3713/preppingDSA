#include<bits/stdc++.h>
using namespace std;
class Solution{
    
  public:
        int LIS(vector<int>&nums){
        int n = nums.size();
        vector<int>res;
        res.push_back(nums[0]);
        for(int i=1;i<n;i++){

            if(nums[i] > res.back()) res.push_back(nums[i]);
            else{
                int ind = lower_bound(res.begin(), res.end(), nums[i])-res.begin();
                res[ind] = nums[i];
            }
        }
        return res.size();
        }
};
int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    
    // Creating an object of Solution class
    Solution sol;
    int lengthOfLIS = sol.LIS(nums);
    
    cout << "The length of the LIS for the given array is: " << lengthOfLIS << endl;
    
    return 0;
}