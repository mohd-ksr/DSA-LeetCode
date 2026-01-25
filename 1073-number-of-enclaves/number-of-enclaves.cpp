class Solution {
private:
    int r, c;
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>&seen){
        if(i<0 || i>=r || j<0 || j>=c || seen[i][j] || grid[i][j]==0)return;
        seen[i][j]=true;
        dfs(grid, i-1, j, seen);
        dfs(grid, i, j-1, seen);
        dfs(grid, i+1, j, seen);
        dfs(grid, i, j+1, seen);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        this->r=grid.size();
        this->c=grid[0].size();

        vector<vector<bool>>seen(r, vector<bool>(c, false));

        for(int i=0; i<r; i++){
            if(grid[i][0]==1 && !seen[i][0])dfs(grid, i, 0, seen);
            if(grid[i][c-1]==1 && !seen[i][c-1])dfs(grid, i, c-1, seen);
        }
        for(int j=0; j<c; j++){
            if(grid[0][j]==1 && !seen[0][j])dfs(grid, 0, j, seen);
            if(grid[r-1][j]==1 && !seen[r-1][j])dfs(grid, r-1, j, seen);
        }

        int totalOnes = 0;
        int boundryOnes = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                totalOnes+=(grid[i][j]==1);
                boundryOnes+=(seen[i][j]);
            }
        }

        return totalOnes-boundryOnes;
    }
};