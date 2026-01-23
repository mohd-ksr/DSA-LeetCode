class Solution {
private:   
    int row;
    int col;
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]=='0')return;
        grid[i][j]='0';
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        this->row = grid.size();
        this->col = grid[0].size();
        int ans = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};