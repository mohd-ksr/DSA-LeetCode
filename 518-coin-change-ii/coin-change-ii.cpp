class Solution {
private:
    int solve(int ind, int sum, vector<int>& coins,  vector<vector<long long>>&dp){
        if(sum==0)return 1;
        if(ind<=0)return 0;

        if(dp[ind-1][sum]!=-1)return dp[ind-1][sum];
        if(coins[ind-1]<=sum){
            return dp[ind-1][sum]=solve(ind, sum-coins[ind-1], coins, dp) + solve(ind-1, sum, coins, dp);
        }
        else return dp[ind-1][sum]=solve(ind-1, sum, coins, dp);
    }
public:
    int change(int sum, vector<int>& coins) {

        int n = coins.size();
        vector<vector<long long>>dp(n+1, vector<long long>(sum+1, -1));
        return solve(n, sum, coins, dp);
    }
};