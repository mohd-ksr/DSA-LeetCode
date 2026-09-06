class Solution {
private:
    unordered_map<string, int>dp;
    int bt(int ind, int j, string &s, string &t){
        if(j==t.size()){
            return 1;
        }
        if(ind>=s.size()){
            return 0;
        }
        string key = to_string(ind)+"#"+to_string(j);
        if(dp.find(key)!=dp.end())return dp[key];
        long long notTake = bt(ind+1, j, s, t);
        long long take = 0;
        if(s[ind]==t[j]){
            take = bt(ind+1, j+1, s, t);
        }

        return dp[key]=take+notTake;
    }
public:
    int numDistinct(string s, string t) {
        return bt(0, 0, s, t);
    }
};