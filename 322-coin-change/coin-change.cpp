class Solution {
private:
    int dfs(vector<int>& coins, int n, int amt, vector<vector<int>>&dp){
        if(amt==0)return 0;
        if(n<0)return 1e9;
        if(dp[n][amt]!=-1)return dp[n][amt];
        int notPick = dfs(coins, n-1, amt, dp);
        int pick = 1e9;
        if(amt>=coins[n]){
            int temp = dfs(coins, n, amt-coins[n],dp);
            if(temp!=1e9)pick=1+temp;
        }
        return dp[n][amt]=min(pick, notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1, -1));
        int ans = dfs(coins, coins.size()-1, amount, dp);
        if(ans>=1e9)return -1;
        return ans;
    }
};