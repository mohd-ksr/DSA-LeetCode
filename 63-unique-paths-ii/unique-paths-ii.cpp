class Solution {
private:
    int solve(vector<vector<int>>& obstacleGrid,int &m, int &n, int i, int j, vector<vector<int>>& dp){
        if(i>=m || j>=n || obstacleGrid[i][j]==1)return 0;
        else if(i==m-1 && j==n-1)return 1;
        else if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solve(obstacleGrid,m,n,i+1,j,dp)+solve(obstacleGrid,m,n,i,j+1,dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return solve(obstacleGrid,m,n,0,0,dp);

        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1)return 0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            if(obstacleGrid[i][0]==1)break;
            dp[i][0]=1;
        }
        for(int j=1; j<n; j++){
            if(obstacleGrid[0][j]==1)break;
            dp[0][j]=1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]==1)dp[i][j]=0;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// Time Complexity: O(m·n)
// Space Complexity: O(m·n)