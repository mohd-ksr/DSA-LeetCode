class Solution {
private:
    int solve(vector<int>& nums, int ind, vector<int>&dp){
        if(ind>=nums.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        return dp[ind]=max(nums[ind]+solve(nums,ind+2, dp), solve(nums,ind+1, dp));
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return solve(nums, 0, dp);
    }
};