class Solution {
private: 
    int MOD = 1e9 + 7;
    int dfs(vector<vector<int>>& grid, int &n, int &m, int i, int j, int rem, int &k, vector<vector<vector<int>>>&dp){
        if(i<0 || i>=n || j<0 || j>=m)return 0;
        if(i==n-1 && j==m-1){
            return (rem+grid[i][j])%k==0;
        }
        if(dp[i][j][rem]!=-1)return dp[i][j][rem];
        long long ans=0;
        ans+=dfs(grid,n,m,i+1,j,(rem+grid[i][j])%k,k,dp);
        ans+=dfs(grid,n,m,i,j+1,(rem+grid[i][j])%k,k,dp);
        return dp[i][j][rem] = ans%MOD;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return dfs(grid,n,m,0,0,0,k,dp);
    }
};
// Time Complexity O(n*m*k)
// Space Complexity O(n*m*k)