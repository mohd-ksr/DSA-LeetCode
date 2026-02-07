class Solution {
private:
    int r,c;
    int dfs(vector<vector<int>>&grid, int i, int j, int rem){
        if(i<0 || i>=r || j<0 || j>=c || grid[i][j]==-1)return 0;
        if(grid[i][j]==2)return rem==0;
        int temp=grid[i][j];
        grid[i][j]=-1;
        int path = (dfs(grid, i-1, j, rem-1)+dfs(grid, i, j-1, rem-1)+dfs(grid, i+1, j, rem-1)+dfs(grid, i, j+1, rem-1));
        grid[i][j]=temp;
        return path;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        this->r = grid.size();
        this->c = grid[0].size();
        int count_0 = 0;
        int x=-1, y=-1;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==0)count_0++;
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }
        return dfs(grid, x, y, count_0+1);
    }
};