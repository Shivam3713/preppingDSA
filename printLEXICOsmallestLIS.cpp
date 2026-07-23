#include<bits/stdc++.h>
using namespace std;
vector<int>solve(int ind, int n, vector<int>&arr){
    vector<int>dp(n, 1);
    vector<int>prev(n, -1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                if(dp[j]+1> dp[i]){
                    dp[i] = dp[j]+1;
                    prev[i]=j;
                }
            }
        }
    }
    int maxlen=0, maxprev=0;
    for(int i=0;i<n;i++){
        if(dp[i] > maxlen){
            maxlen =dp[i];
            maxprev = i;
        }   
    }
    vector<int>ans;
    while(maxprev != -1){
        ans.push_back(arr[maxprev]);
        maxprev = prev[maxprev];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    vector<int>arr={5, 4, 11, 1, 16, 8};
    int n = arr.size();
    vector<int>res = solve(0, n, arr);
    for(auto it: res) cout<<it<<" ";
}