class Solution {
private:
    int solve(int n, int m, string &text1, string &text2, vector<vector<int>>&dp){
        if(n==0 || m==0)return 0;
        if(dp[n-1][m-1]!=-1)return dp[n-1][m-1];
        if(text1[n-1]==text2[m-1])return dp[n-1][m-1]=1+solve(n-1, m-1, text1, text2, dp);
        else{
            return dp[n-1][m-1]=max(solve(n-1, m, text1, text2, dp), solve(n, m-1, text1, text2, dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, text1, text2, dp);
    }
};