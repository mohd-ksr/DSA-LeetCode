class Solution {
private:
    int r, c;
    void dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i>=r || j<0 || j>=c || grid[i][j]!=1)return;
        grid[i][j]=-1;
        dfs(i-1, j, grid);
        dfs(i, j-1, grid);
        dfs(i+1, j, grid);
        dfs(i, j+1, grid);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        this->r = grid.size();
        this->c = grid[0].size();
        for(int j=0; j<c; j++){
            if(grid[0][j]==1)dfs(0, j, grid);
            if(grid[r-1][j]==1)dfs(r-1, j, grid);
        }
        for(int i=0; i<r; i++){
            if(grid[i][0]==1)dfs(i, 0, grid);
            if(grid[i][c-1]==1)dfs(i, c-1, grid);
        }
        int ans=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ans+=(grid[i][j]==1);
            }
        }
        return ans;
    }
};