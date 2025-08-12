class Solution {
private:
    const int MOD=1e9 + 7;
    int dfs(int ind, int remaining,vector<int>&powers,vector<vector<int>>&dp){
        if(remaining==0)return 1;
        if(ind==powers.size() || remaining<0)return 0;
        if(dp[ind][remaining]!=-1)return dp[ind][remaining];
        int skip=dfs(ind+1,remaining,powers,dp);
        int take=dfs(ind+1,remaining-powers[ind],powers,dp);
        return dp[ind][remaining]=(skip+take)%MOD;
    }
public:
    int numberOfWays(int n, int x) {
        vector<int>powers;
        for(int i=1; pow(i,x)<=n; i++){
            powers.push_back((int)pow(i,x));
        }
        vector<vector<int>>dp(powers.size()+1,vector<int>(n+1,-1));
        return dfs(0,n,powers,dp);

    }
};
// Time complexity O(m×n)
// Space complexity O(mxn) where m is size of powers vector