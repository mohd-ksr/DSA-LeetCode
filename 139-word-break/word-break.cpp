class Solution {
private:
    bool solve(int start, string &s, vector<string>& wordDict, vector<int>&dp){
        if(start == s.size()) return true;
        if(dp[start]!=-1)return dp[start];
        for(string &word : wordDict){
            int len = word.size();
            
            if(start + len <= s.size() && s.substr(start, len) == word){
                if(solve(start + len, s, wordDict, dp))
                    return dp[start]=true;
            }
        }
        return dp[start]=false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1, -1);
        return solve(0, s, wordDict, dp);
    }
};