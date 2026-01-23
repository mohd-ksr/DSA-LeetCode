class Solution {
private:   
    const int inf = 1e4+1;
    int solve(int ind, vector<int>& nums,vector<int>&dp){
        if(ind>=nums.size()-1)return 0;
        if(nums[ind]==0)return inf;
        
        if(dp[ind]!=-1)return dp[ind];

        int ans = inf;
        for(int i=1; i<=nums[ind]; i++){
            ans = min(ans, 1+solve(ind+i, nums,dp));
        }
        return dp[ind]=ans;
    }
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return solve(0,nums,dp);
    }
};