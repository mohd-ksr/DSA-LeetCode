class Solution {
private:
    int sol(vector<int>& cost, int ind, vector<int>&dp){
        if(ind>=cost.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int oneStep = cost[ind] + sol(cost, ind+1, dp);
        int twoStep = cost[ind] + sol(cost, ind+2, dp);

        return dp[ind]=min(oneStep, twoStep);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1, -1);
        int startWith0 = sol(cost, 0, dp);
        int startWith1 = sol(cost, 1, dp);
        return min(startWith0, startWith1);
    }
};