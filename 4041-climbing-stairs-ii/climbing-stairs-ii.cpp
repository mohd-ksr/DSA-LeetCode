class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n==1) return costs[0]+1;
        vector<long long>dp(n+1, LLONG_MAX);
        dp[0] = 0L;
        dp[1] = costs[0] + 1LL;
        dp[2] = min(dp[1] + costs[1] + 1LL, dp[0] + costs[1] + 4LL);
        for(int j = 3; j<=n; j++){
            dp[j] = min(dp[j], (long long)(costs[j-1] + 1LL) + dp[j-1]);
            dp[j] = min(dp[j], (long long)(costs[j-1] + 4LL) + dp[j-2]);
            dp[j] = min(dp[j], (long long)(costs[j-1] + 9LL) + dp[j-3]);
        }
        return (int)dp[n];
    }
};