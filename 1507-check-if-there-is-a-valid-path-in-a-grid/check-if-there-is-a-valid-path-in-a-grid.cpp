class Solution {
public:
    int m, n;
    vector<vector<pair<int,int>>> dirs = {
        {},
        {{0,-1}, {0,1}},   
        {{-1,0}, {1,0}},  
        {{0,-1}, {1,0}},   
        {{0,1}, {1,0}},    
        {{0,-1}, {-1,0}},  
        {{0,1}, {-1,0}}  
    };
    
    bool isConnected(int x, int y, int nx, int ny, vector<vector<int>>& grid) {
        for (auto &d : dirs[grid[nx][ny]]) {
            if (nx + d.first == x && ny + d.second == y)
                return true;
        }
        return false;
    }
    
    bool dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if (x == m - 1 && y == n - 1) return true;
        
        vis[x][y] = true;
        
        for (auto &d : dirs[grid[x][y]]) {
            int nx = x + d.first;
            int ny = y + d.second;
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny]) {
                if (isConnected(x, y, nx, ny, grid)) {
                    if (dfs(nx, ny, grid, vis))
                        return true;
                }
            }
        }
        return false;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        return dfs(0, 0, grid, vis);
    }
};