#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n), right(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while( !st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                right[i] = st.empty()?n:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        // stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i] ){
                st.pop();
            }
            left[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        int maxArea = INT_MIN;
        for(int i=0;i<n;i++){
            int ans = (right[i]-left[i]-1)*heights[i];
            maxArea = max(maxArea, ans);
        }
        return maxArea;
    }
};
int main(){
    vector<int>arr ={2,1,5,6,2,3,1 };
    Solution* s = new Solution();
    cout<<s->largestRectangleArea(arr);
}