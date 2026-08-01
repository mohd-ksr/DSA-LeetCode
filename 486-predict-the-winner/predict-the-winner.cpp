class Solution {
private:
    unordered_map<string, bool>dp;
    bool solve(int s, int e, int p1, int p2, bool isP1,vector<int>& nums){
        if(s>e){
            return p1>=p2;
        }
        string key = to_string(s)+"#"+to_string(e)+"#"+to_string(p1)+"#"+to_string(p2);
        if(dp.count(key))return dp[key];
        bool ans;
        if(isP1){
            ans = solve(s+1, e, p1+nums[s], p2, false, nums)||solve(s, e-1, p1+nums[e], p2, false, nums);
        }
        else{
            ans = solve(s+1, e, p1, p2+nums[s], true, nums)&&solve(s, e-1, p1, p2+nums[e], true, nums);
        }
        return dp[key]=ans;   
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return solve(0, nums.size()-1, 0, 0, true, nums);
    }
};