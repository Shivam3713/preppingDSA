class Solution{    
    public:
    int solve(int i, int j, vector<int>&student, vector<int>&cookie, vector<vector<int>>&dp){
        if(i>=student.size() || j>=cookie.size()) return 0;
        if( dp[i][j]!= -1 )return dp[i][j];
        int take=0;
        if(cookie[j]>= student[i]){ take = 1+solve(i+1, j+1, student, cookie, dp);}
        take = max(take, solve(i, j+1, student, cookie, dp));
        return dp[i][j]= take;

    }
    int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
        //your code goes here
        int n = Student.size();
        int m = Cookie.size();
        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, Student, Cookie, dp);
    }
};

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> Student(n);
    for (int i = 0; i < n; i++) {
        cin >> Student[i];
    }

    cin >> m;

    vector<int> Cookie(m);
    for (int i = 0; i < m; i++) {
        cin >> Cookie[i];
    }

    Solution obj;
    cout << obj.findMaximumCookieStudents(Student, Cookie) << endl;

    return 0;
}