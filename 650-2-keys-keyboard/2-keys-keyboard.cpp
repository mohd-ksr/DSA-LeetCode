class Solution {
private:    
    int solve(int n, int cl, int pl, vector<vector<int>>&dp){
        if(cl==n)return 0;
        if(cl>n)return 1000000;
        if(dp[cl][pl]!=-1)return dp[cl][pl];
        int opt1 = 2 + solve(n, cl*2, cl, dp);
        int opt2 = 1 + solve(n, cl+pl, pl, dp);

        return dp[cl][pl]=min(opt1, opt2);
    }
public:
    int minSteps(int n) {
        if(n==1)return 0;
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return 1+solve(n, 1, 1, dp);
    }
};