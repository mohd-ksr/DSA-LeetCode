class Solution {
private:
    int r,c;
    int dfs(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>&dp){
        if(i>=r || j>=c)return 1e9+7;
        if(i==r-1 && j==c-1)return (dungeon[i][j] < 0)? abs(dungeon[i][j])+1:1;
        if(dp[i][j]!=-1)return dp[i][j];
        int r = dfs(i+1, j, dungeon, dp);
        int l = dfs(i, j+1, dungeon, dp);

        int h = min(l, r)-dungeon[i][j];

        return dp[i][j]=(h<=0)?1:h;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        this->r = dungeon.size();
        this->c = dungeon[0].size();
        vector<vector<int>>dp(r+1, vector<int>(c+1, -1));
        return dfs(0, 0, dungeon, dp);
    }
};