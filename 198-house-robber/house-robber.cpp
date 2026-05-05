class Solution {
private:
    int solve(int ind, vector<int>& nums,bool PisTaken, vector<vector<int>>&dp){
        if(ind>=nums.size())return 0;
        if(dp[ind][PisTaken]!=-1)return dp[ind][PisTaken];
        if(PisTaken){
            return dp[ind][PisTaken]=solve(ind+1, nums, false, dp);
        }
        else{
            return dp[ind][PisTaken]=max(nums[ind]+solve(ind+1, nums, true, dp), solve(ind+1, nums, false, dp));
        }
    }
public:
    int rob(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1, vector<int>(2, -1));
        return solve(0, nums, false, dp);
    }
};