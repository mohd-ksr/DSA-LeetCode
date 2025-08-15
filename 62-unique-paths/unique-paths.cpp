class Solution {
private:
    int solve(int &m,int &n, int i, int j, vector<vector<int>>&dp){
        if(i<0 || i>=m || j<0 || j>=n)return 0;
        else if(i==m-1 && j==n-1)return 1;
        else if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solve(m,n,i+1,j,dp)+solve(m,n,i,j+1,dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n));
        // return solve(m,n,0,0,dp);
        
        for(int i=0; i<m; i++){
            dp[i][0]=1;
        }
        for(int j=0; j<n; j++){
            dp[0][j]=1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// Time Complexity O(mxn)
// Space Complexity O(mxn)