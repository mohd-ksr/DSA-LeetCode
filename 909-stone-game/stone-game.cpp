class Solution {
private:
    unordered_map<string, int>dp;
    int solve(int s, int e,vector<int>&piles){
        if(s==e){
            return piles[s];
        }
        string key = to_string(s)+"#"+to_string(e);
        if(dp.count(key))return dp[key];

        int l = piles[s] - solve(s+1, e, piles);
        int r = piles[e] - solve(s, e-1, piles);
        return dp[key]=max(l,r);
    }
public:
    bool stoneGame(vector<int>& piles) {
        return solve(0, piles.size()-1,piles)>0;
    }
};