class Solution {
private:
    unordered_set<int>st;
    int solve(int cd, vector<int>& days, vector<int>& costs, vector<int>&dp){
        if(cd>days[days.size()-1])return 0;
        if(st.find(cd)==st.end())return solve(cd+1, days, costs, dp);

        if(dp[cd]!=-1)return dp[cd];
        int d1 = costs[0] + solve(cd+1, days, costs, dp);
        int d7 = costs[1] + solve(cd+7, days, costs, dp);
        int d30 = costs[2] + solve(cd+30, days, costs, dp);

        return dp[cd]=min({d1, d7, d30});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int>dp(days[days.size()-1]+1, -1);
        for(auto d:days)st.insert(d);
        return solve(1, days, costs, dp);
    }
};