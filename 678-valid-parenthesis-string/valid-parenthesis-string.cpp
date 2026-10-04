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
        // return solve(0, 0, s);
        int n = s.size();
        // vector<vector<bool>>dp(n+1, vector<bool>(n+1, false));
        // dp[n][0]=true;
        // for(int i=n-1; i>=0; i--){
        //     for(int b=0; b<=n; b++){
        //         if(s[i]=='('){
        //             if(b+1<=n){
        //                 dp[i][b] = dp[i+1][b+1];
        //             }
        //         }
        //         else if(s[i]==')'){
        //             if(b>0){
        //                 dp[i][b] = dp[i+1][b-1];
        //             }
        //         }
        //         else{
        //             dp[i][b] = dp[i+1][b];
        //             if(b+1<=n){
        //                 dp[i][b] = dp[i][b] || dp[i+1][b+1];
        //             }
        //             if(b>0){
        //                 dp[i][b] = dp[i][b] || dp[i+1][b-1];
        //             }
        //         }
        //     }
        // }
        // return dp[0][0];

        int oc=0, cc=0;
        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='*')oc++;
            else oc--;
            if(oc<0)return false;

            if(s[n-i-1]==')' || s[n-i-1]=='*')cc++;
            else cc--;
            if(cc<0)return false;

        }
        return true;
    }
};