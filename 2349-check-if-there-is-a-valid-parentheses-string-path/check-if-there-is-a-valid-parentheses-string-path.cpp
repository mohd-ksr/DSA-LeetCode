class Solution {
private:
    int r, c;
    unordered_map<string, bool>dp;
    bool solve(int i, int j, vector<vector<char>>& grid, int b){
        if(i<0 || i>=r || j<0 || j>=c || b<0)return false;
        if(grid[i][j]=='(')b++;
        else b--;
        if(i==r-1 && j==c-1){
            return b==0;
        }
        string key = to_string(i)+"#"+to_string(j)+"#"+to_string(b);
        if(dp.find(key)!=dp.end())return dp[key];
        return dp[key]=solve(i+1, j, grid, b) || solve(i, j+1, grid, b);
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        this -> r = grid.size();
        this -> c = grid[0].size();
        return solve(0, 0, grid, 0);
    }
};