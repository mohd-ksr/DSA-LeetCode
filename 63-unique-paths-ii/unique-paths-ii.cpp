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
        // vector<vector<int>>dp(r, vector<int>(c, -1));
        // return dfs(grid, 0, 0, dp);
        vector<vector<int>>dp(r, vector<int>(c, 0));
        if(grid[0][0]==1)return 0;
        dp[0][0]=1;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1)dp[i][j]=0;
                else{
                    if(i>0)dp[i][j] += dp[i-1][j];
                    if(j>0)dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[r-1][c-1];
    }
};