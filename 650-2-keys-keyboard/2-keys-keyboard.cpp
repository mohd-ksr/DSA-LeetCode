class Solution {
private: 
    int solve(int n, int curLen, int pasteLen, vector<vector<int>>&dp){
        if(curLen==n)return 0;
        if(curLen>n)return 1000;
        if(dp[curLen][pasteLen]!=0)return dp[curLen][pasteLen];
        int opt1 = 2+solve(n, curLen*2, curLen,dp);
        int opt2 = 1 + solve(n, curLen+pasteLen, pasteLen,dp);

        return dp[curLen][pasteLen]=min(opt1, opt2);
    }
public:
    int minSteps(int n) {
        if(n==1)return 0;
        vector<vector<int>>dp(n+1, vector<int>(n/2+1, 0));
        return 1+solve(n,1,1,dp);
    }
};