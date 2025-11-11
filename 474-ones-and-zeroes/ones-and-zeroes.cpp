class Solution {
private:
    int n11(string s){
        int ans=0;
        for(char &ch:s)if(ch=='1')ans++;
        return ans;
    }
    int dfs(vector<string>& strs, int m, int n, int i, vector<vector<vector<int>>>&dp){
        if(i==strs.size())return 0;
        if(dp[m][n][i]!=-1)return dp[m][n][i];
        string tempStr = strs[i];
        int n1 = n11(tempStr);
        int n0 = tempStr.size()-n1;

        int notTake = dfs(strs, m, n ,i+1, dp);
        int take = 0;
        if(m>=n0 && n>=n1){
            take  = 1 + dfs(strs, m-n0, n-n1, i+1, dp);
        }

        return dp[m][n][i]=max(take, notTake);
       
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(strs.size()+1,-1)));
        return dfs(strs, m, n, 0, dp);
    }
};