class Solution {
private:
    int solve(int m, int n, int i, int j, vector<vector<int>>&dp){
        if(i>=m || i<0 || j>=n || j<0)return 0;
        if(i==m-1 && j==n-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int l = solve(m, n, i, j+1, dp);
        int d = solve(m, n, i+1, j, dp);

        return dp[i][j]=l+d;
        
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return solve(m, n, 0, 0, dp);
    }
};