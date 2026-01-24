class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0; 
        for(auto &n:nums)sum+=n;
        if(sum%2!=0)return false;

        sum = sum/2;
        int n = nums.size();
        vector<vector<bool>>dp(n+1, vector<bool>(sum+1));

        for(int i=0; i<=n; i++){
            dp[i][0]=true;
        }
        for(int j=1; j<=sum; j++){
            dp[0][j]=false;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        return dp[n][sum];
    }
};

// TC = O(n * (sum/2)) = O(n * sum)
// SC = O(n * sum)

