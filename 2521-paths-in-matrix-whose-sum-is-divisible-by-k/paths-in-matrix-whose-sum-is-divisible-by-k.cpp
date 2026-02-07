class Solution {
private:
    int r, c;
    const int mod = 1e9+7;
    int dfs(vector<vector<int>>& grid, int i, int j, int sum, int &k, vector<vector<bool>>&vis, vector<vector<vector<int>>>&dp){
        if(i<0 || i>=r || j<0 || j>=c || vis[i][j])return 0;
        sum+=grid[i][j];
        if(i==r-1 && j==c-1){
            return sum%k==0;
        }
        if(dp[i][j][sum%k]!=-1)return dp[i][j][sum%k];
        vis[i][j]=true;
        int right = dfs(grid, i, j+1, sum, k, vis, dp);
        int down = dfs(grid, i+1, j, sum, k, vis, dp);
        vis[i][j]=false;
        return  dp[i][j][sum%k]=(right%mod + down%mod)%mod;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        this->r = grid.size();
        this->c = grid[0].size();
        vector<vector<bool>>vis(r, vector<bool>(c, false));
        // vector<vector<int>>dp(r, vector<int>(c, -1));
        vector<vector<vector<int>>>dp(r+1, vector<vector<int>>(c+1, vector<int>(k+1, -1)));
        return dfs(grid, 0, 0, 0, k, vis, dp);
    }
};