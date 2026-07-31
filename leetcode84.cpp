#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>left(n), right(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) {
                st.pop();
            }
            right[i]= st.empty()?n:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            left[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int res = heights[i]*(right[i]-left[i]-1);
            ans = max(ans, res);
        }
        return ans;
    }
};
int main(){
    vector<int>arr ={2,1,5,6,2,3,1 };
    Solution* s = new Solution();
    cout<<s->largestRectangleArea(arr);
}