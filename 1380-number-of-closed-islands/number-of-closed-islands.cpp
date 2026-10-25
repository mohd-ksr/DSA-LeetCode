class Solution {
private:
    int r,c;
    void makeOne(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i>=r || j<0 || j>=c || grid[i][j]!=0)return;
        grid[i][j]=1;
        makeOne(i+1, j, grid);
        makeOne(i-1, j, grid);
        makeOne(i, j+1, grid);
        makeOne(i, j-1, grid);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        this->r = grid.size();
        this->c = grid[0].size();
        for(int i=0; i<r; i++){
            if(grid[i][0]==0)makeOne(i, 0, grid);
            if(grid[i][c-1]==0)makeOne(i, c-1, grid);
        }
        for(int j=0; j<c; j++){
            if(grid[0][j]==0)makeOne(0, j, grid);
            if(grid[r-1][j]==0)makeOne(r-1, j, grid);
        }
        int ans = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==0){
                    makeOne(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
