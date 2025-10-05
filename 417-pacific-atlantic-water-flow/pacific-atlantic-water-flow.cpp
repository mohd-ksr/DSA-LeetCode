class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c) {
        ocean[r][c] = true;
        for(auto& dir :directions){
            int nr = r + dir[0];
            int nc = c + dir[1];
            if(nr<0 || nc<0 || nr>=m || nc >= n) continue;
            if(ocean[nr][nc]) continue;
            if(heights[nr][nc] < heights[r][c]) continue;
            dfs(heights, ocean, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; ++i)
            dfs(heights, pacific, i, 0);
        for(int j = 0; j < n; ++j)
            dfs(heights, pacific, 0, j);
        
        for(int i = 0; i < m; ++i)
            dfs(heights, atlantic, i, n - 1);
        for (int j = 0; j < n; ++j)
            dfs(heights, atlantic, m - 1, j);
        
        vector<vector<int>> result;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};