class Solution {
private:
    const int inf = 1e9;
    int solve(int ind, int sum, vector<int>& coins, vector<vector<int>>&dp){
        if(sum==0)return 0;
        if(ind<=0)return inf;
        if(dp[ind-1][sum]!=-1)return dp[ind-1][sum];
        if(coins[ind-1]<=sum){
            return dp[ind-1][sum]=min(1+solve(ind, sum-coins[ind-1], coins, dp), solve(ind-1, sum, coins, dp));
        }
        else return dp[ind-1][sum]=solve(ind-1, sum, coins, dp);

    }
public:
    int coinChange(vector<int>& coins, int sum) {
        // int n = coins.size();
        // vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        // int res = solve(n, sum, coins, dp);
        // return (res==inf? -1:res);

        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(sum+1, inf));
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(coins[i-1]<=j){
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return (dp[n][sum]==inf? -1:dp[n][sum]);
        
    }
};



