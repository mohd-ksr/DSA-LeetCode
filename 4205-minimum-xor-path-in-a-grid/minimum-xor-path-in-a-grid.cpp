class Solution {
private:
    int r,c;
    // unordered_map<string, int>dp;
    vector<vector<vector<int>>>dp;
    int dfs(int i, int j, int curr, vector<vector<int>>& grid){
        if(i<0 || i>=r || j<0 || j>=c)return INT_MAX;
        if(i==r-1 && j==c-1){
            return curr^grid[i][j];
        }
        if(dp[i][j][curr]!=-1)return dp[i][j][curr];
        return dp[i][j][curr] = min(dfs(i+1, j, curr^grid[i][j], grid), dfs(i, j+1, curr^grid[i][j], grid));
    }
public:
    int minCost(vector<vector<int>>& grid) {
        this-> r = grid.size();
        this-> c = grid[0].size();
        dp.resize(r, vector<vector<int>>(c, vector<int>(1024, -1)));
        return dfs(0, 0, 0, grid);
    }
};