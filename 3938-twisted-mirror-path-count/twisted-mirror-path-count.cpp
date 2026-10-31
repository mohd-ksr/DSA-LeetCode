class Solution {
private:
    int r, c;
    vector<vector<vector<int>>>dp;
    const int mod = 1e9+7;
    int solve(int i, int j, vector<vector<int>>&grid, int dir){
        if(i>=r || i<0 || j>=c || j<0)return 0;
        if(i==r-1 && j==c-1)return 1;
        if(dp[i][j][dir]!=-1)return dp[i][j][dir];
        if(grid[i][j]==1){
            if(dir==1)return dp[i][j][dir]=(solve(i+1, j, grid, 0))%mod;
            else return dp[i][j][dir]=(solve(i, j+1, grid, 1))%mod;
        }
        else return dp[i][j][dir]=((solve(i+1, j, grid, 0))%mod + (solve(i, j+1, grid, 1))%mod)%mod;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        dp.resize(r+1, vector<vector<int>>(c+1, vector<int>(2, -1)));
        return solve(0, 0, grid, 0);
    }
};