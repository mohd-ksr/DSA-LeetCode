class Solution {
private:
    int solve(int day, vector<int>&prices, int hold, vector<vector<int>>&dp){
        if(day>=prices.size())return 0;
        if(dp[day][hold]!=-1)return dp[day][hold];
        if(hold){
            return dp[day][hold]=max(prices[day], solve(day+1, prices, hold, dp));
        }
        else{
            return dp[day][hold]=max(-prices[day]+solve(day+1, prices, !hold, dp), solve(day+1, prices, hold, dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1, vector<int>(2, -1));
        return solve(0, prices, 0, dp);
    }
};