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
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        int res  = solve(0, coins, amount, dp);
        return (res==1e9)?-1:res;

    }
};