class Solution {
private:
    int row, col;
    void dfs(vector<vector<int>>& grid2, int i, int j,  vector<pair<int, int>>&p){
        if(i<0 || i>=row || j<0 || j>=col || grid2[i][j]==0)return ;
        grid2[i][j]=0;
        p.push_back({i, j});
        dfs(grid2, i-1, j, p);
        dfs(grid2, i, j-1, p);
        dfs(grid2, i+1, j, p);
        dfs(grid2, i, j+1, p);
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        this->row = grid1.size();
        this->col = grid1[0].size();

        int ans=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid2[i][j]==1){
                    vector<pair<int, int>>p;
                    dfs(grid2, i, j, p);
                    int ok=true;
                    for(auto [x, y]:p){
                        if(grid1[x][y]==0){
                            ok=false;
                            break;
                        }
                    }
                    if(ok)ans++;
                }
            }
        }

        return ans;
    }
};