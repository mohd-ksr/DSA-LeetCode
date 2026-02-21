class Solution {
private:
    int solve(int ind, int sum, vector<int>& coins, vector<vector<int>>&dp){
        if(ind>=coins.size())return 0;
        if(sum==0)return 1;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        if(coins[ind]<=sum){
            return dp[ind][sum]=solve(ind, sum-coins[ind], coins, dp) + solve(ind+1, sum, coins, dp);
        }
        else return dp[ind][sum]=solve(ind+1, sum, coins, dp);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        return solve(0, amount, coins, dp);
    }
};