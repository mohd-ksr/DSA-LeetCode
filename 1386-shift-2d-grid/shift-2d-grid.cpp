class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        k = k%(r*c);
        while(k--){
            int last = grid[r-1][c-1];
            for(int i=r-1; i>=0; i--){
                for(int j=c-1; j>0; j--){
                    grid[i][j] = grid[i][j-1];
                }
                if(i!=0){
                    grid[i][0] = grid[i-1][c-1];
                }
            }
            grid[0][0]=last;
        }
        return grid;
    }
};