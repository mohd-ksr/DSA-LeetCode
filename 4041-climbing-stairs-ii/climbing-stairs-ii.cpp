class Solution {
private:
    int n;
    vector<long long>dp;
    long long solve(int ind, vector<int>& costs){
        if(ind>=n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        long long ans = LLONG_MAX;
        for(int i=ind+1; i<=min(n, ind+3); i++){
            long long val = (long long)(i-ind);
            ans = min(ans, ((long long)costs[i] + val*val) + solve(i, costs));
        }
        return dp[ind] = ans;
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        reverse(costs.begin(), costs.end());
        costs.push_back(0);
        reverse(costs.begin(), costs.end());
        this->n = n;
        dp.resize(n+1, -1);
        return (int)solve(0, costs);
    }
};