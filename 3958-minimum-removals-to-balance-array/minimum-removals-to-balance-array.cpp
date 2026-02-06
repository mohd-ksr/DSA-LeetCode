class Solution {
private:
    const int inf = 1e9+7;
    int solve(vector<int>& nums, int i, int j, int &k, vector<vector<int>>&dp){
        if(i>j)return inf;
        double mini = nums[i];
        double maxi = nums[j];
        double div = k;
        cout<<maxi/k<<" ";
        if((maxi/div)<=mini || i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=1+min(solve(nums, i+1, j, k, dp), solve(nums, i, j-1, k, dp));
    }
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        // return solve(nums, 0, n-1, k, dp);
        int ans = n, j=0;
        for(int i=0; i<n; i++){
            while(j<n && nums[j]<=static_cast<long long>(nums[i])*k)j++;
            ans=min(ans, n-(j-i));
        }
        return ans;
    }
};
