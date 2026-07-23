#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>nums = {5, 1, 4, 2, 3, 6, 8, 7};
    int n = nums.size();
    vector<int>dp1(n, 1);
    vector<int>dp2(n, 1);

    for(int i=1;i<n;i++){
        for(int j =0;j<i;j++){
            if(nums[i]>nums[j] && dp1[i]<1+dp1[j]){
                dp1[i]= 1+dp1[j];
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j =i;j<n;j++){
            if(nums[i]>nums[j] && dp2[i]<1+dp2[j]){
                dp2[i]= 1+dp2[j];
            }
        }
    }
    int res = INT_MIN;
    for(int i=0;i<n;i++){
        res = max(res, dp1[i]+dp2[i]-1);
    }
    cout<< res;
}