#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr ={3, 8, 15, 32, 64};
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int>dp(n, 1); //every number is divisble by istelf;
    vector<int>prev(n, -1) ;//ind of prev where nums[i] is divisible by nums[j];
    for(int i=1;i<n;i++){
        for(int j =0;j<i;j++){
            if(arr[i]%arr[j] ==  0 && dp[i]<dp[j]+1){
                dp[i] = 1+dp[j];
                prev[i]=j;
            }
        }
    }
    int maxlen =0, maxprev =0;
    for(int i=0;i<n;i++){
        if(dp[i] > maxlen){
            maxlen = dp[i];
            maxprev=  i;
        }
    }
    vector<int>ans;
    while(maxprev != -1){
        ans.push_back(arr[maxprev]);
        maxprev = prev[maxprev];
    }
    reverse(ans.begin(), ans.end());    
    for(auto it: ans) cout<<it <<" ";
}
