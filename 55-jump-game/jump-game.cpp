class Solution {
private:
    bool solve(int ind, vector<int>&nums, vector<int>&dp){
        if(ind==nums.size()-1)return true;
        if(ind>=nums.size())return false;
        if(dp[ind]!=-1)return dp[ind];
        bool ans = false;
        for(int i=1; i<=nums[ind]; i++){
           if(solve(ind+i, nums, dp))return dp[ind]=true;
        }
        return dp[ind]=false;

    }
public:
    bool canJump(vector<int>& nums) {
        // vector<int>dp(nums.size()+1, -1);
        // return solve(0, nums, dp);
        int khaTakJaSaktaHai = 0;
        for(int abhiYhaHai = 0; abhiYhaHai<nums.size(); abhiYhaHai++){
            if(abhiYhaHai > khaTakJaSaktaHai)return false;
            khaTakJaSaktaHai = max(khaTakJaSaktaHai, nums[abhiYhaHai]+abhiYhaHai);
        }
        return true;
        
    }
};

// Time Complexity O(n)