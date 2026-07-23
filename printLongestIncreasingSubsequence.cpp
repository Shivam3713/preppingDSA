#include<bits/stdc++.h>
using namespace std;
class Solution{
public : 
    vector<int>longestIncreasingSubsequence(vector<int>&nums){
        int n = nums.size();
        vector<int>res;
        res.push_back(nums[0]);
        int prev=-1;
        for(int i=1;i<n;i++){
            if(nums[i]<res.back()) continue;
            else{
                res.push_back(nums[i]);
            }
        }
        return res;

}
};
int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Solution sol;
    vector<int> lis = sol.longestIncreasingSubsequence(nums);

    cout << "LIS: ";
    for (int x : lis) cout << x << " ";
    cout << endl;

    return 0;
}