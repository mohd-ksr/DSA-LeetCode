class Solution {
private:
    void dfs(int &r, int &c, int i, int j, vector<vector<char>>&grid){
        if(i<0 || i>=r || j<0 || j>=c || grid[i][j]!='1')return;
        grid[i][j]='0';
        dfs(r,c,i-1,j,grid);
        dfs(r,c,i+1,j,grid);
        dfs(r,c,i,j-1,grid);
        dfs(r,c,i,j+1,grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int count=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(r,c,i,j,grid);
                }
            }
        }
        return count;
    }
};