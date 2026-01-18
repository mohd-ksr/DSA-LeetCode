class Solution {
private:
    int calculate(int n, vector<int>&dp){
        if(n==0 || n==1)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=calculate(n-1, dp)+calculate(n-2, dp);
    }
public:
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return calculate(n, dp);
    }
};