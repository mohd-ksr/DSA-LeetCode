class Solution {
private:
    int r,c;
    vector<vector<int>>grid;
    int dfs(int i, int j, int k, vector<vector<vector<int>>>&dp){
        if(i>=r || j>=c)return INT_MIN;

        int cost = (grid[i][j]==0?0:1);
        if(k<cost)return INT_MIN;

        if(dp[i][j][k]!=-1)return dp[i][j][k];

        if(i==r-1 && j==c-1)return grid[i][j];

        int r = dfs(i, j+1, k-cost,dp);
        int d = dfs(i+1, j, k-cost,dp);

        int b = max(r,d);
        if(b==INT_MIN)return dp[i][j][k] = INT_MIN;
        return dp[i][j][k]=b+grid[i][j];
        
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        this->r = grid.size();
        this->c = grid[0].size();
        this->grid = grid;
        vector<vector<vector<int>>>dp(r, vector<vector<int>>(c, vector<int>(k+1,-1)));
        int score = dfs(0,0,k,dp);
        return score==INT_MIN?-1:score;
    }
};