class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        int time = 0;
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int elev = top[0], r = top[1], c = top[2];

            time = max(time, elev);

            if(r == n-1 && c==n-1)
                return time;

            for(auto [dr, dc] : dirs){
                int nr = r + dr, nc = c + dc;
                if(nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }
        return -1; 
    }
};