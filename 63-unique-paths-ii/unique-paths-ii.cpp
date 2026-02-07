class Solution {
private:
    int r,c;
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&dp){
        if(i>=r || j>=c || grid[i][j]==1)return 0;
        if(i==r-1 && j==c-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];

        return dp[i][j] = dfs(grid, i+1, j, dp) + dfs(grid, i, j+1, dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        this->r = grid.size();
        this->c = grid[0].size();
        vector<vector<int>>dp(r, vector<int>(c, -1));
        return dfs(grid, 0, 0, dp);
    }
};