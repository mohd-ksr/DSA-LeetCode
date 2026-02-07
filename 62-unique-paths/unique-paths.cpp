class Solution {
private:
    int r,c;
    int dfs(int i, int j, vector<vector<int>>&dp){
        if(i>=r || j>=c)return 0;
        if(i==r-1 && j==c-1) return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=dfs(i+1, j, dp)+dfs(i, j+1, dp);
    }
public:
    int uniquePaths(int m, int n) {
        this->r = m;
        this->c = n;
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return dfs(0,0, dp);
    }
};