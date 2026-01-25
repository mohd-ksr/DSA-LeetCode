class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto &n:nums)sum+=n;

        if(sum<abs(target)|| (sum+target)%2!=0)return 0;

        target = (sum+target)/2;

        vector<int>dp(target+1, 0);
        dp[0]=1;

        for(auto &n:nums){
            for(int j=target; j>=n; j--){
                dp[j] += dp[j-n];
            }
        }

        return dp[target];
    }
};