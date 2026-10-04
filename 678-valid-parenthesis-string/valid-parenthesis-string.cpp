class Solution {
private:
    unordered_map<string, bool>dp;
    bool solve(int ind, int b, string &s){
        if(b < 0) return false;
        if(ind==s.size()){
            return b==0;
        }

        string key = to_string(ind)+"#"+to_string(b);
        if(dp.find(key)!=dp.end())return dp[key];

        bool ans;
        if(s[ind]=='(')ans = solve(ind+1, b+1, s);
        else if(s[ind]==')')ans =  solve(ind+1, b-1, s);
        else{
            ans =  solve(ind+1, b, s) || solve(ind+1, b+1, s) || solve(ind+1, b-1, s);
        }
        return dp[key] = ans;
    }
public:
    bool checkValidString(string s) {
        return solve(0, 0, s);
    }
};