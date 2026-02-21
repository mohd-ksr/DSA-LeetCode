class Solution {
private:
    int solve(int ind, vector<int>& coins, int sum, vector<vector<int>>&dp){
        if(ind>=coins.size())return 1e9;
        if(sum==0)return 0;
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        if(coins[ind]<=sum){
            return dp[ind][sum]=min(1+solve(ind, coins, sum-coins[ind], dp), solve(ind+1, coins, sum, dp));
        }
        else return dp[ind][sum]=solve(ind+1, coins, sum,dp);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        // int res  = solve(0, coins, amount, dp);
        // return (res==1e9)?-1:res;
        vector<vector<int>>dp(n+1, vector<int>(amount+1,1e9));
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                if(coins[i-1]<=j){
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (dp[n][amount]==1e9?-1:dp[n][amount]);
    }
};