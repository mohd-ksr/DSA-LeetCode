class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n - 1], i, n - 1});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            if (!visited[0][j]) {
                pq.push({heightMap[0][j], 0, j});
                visited[0][j] = true;
            }
            if (!visited[m - 1][j]) {
                pq.push({heightMap[m - 1][j], m - 1, j});
                visited[m - 1][j] = true;
            }
        }

        int water = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto cell = pq.top(); pq.pop();
            int h = cell[0], i = cell[1], j = cell[2];

            for (auto& d : dirs) {
                int x = i + d[0], y = j + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                    visited[x][y] = true;
                    if (heightMap[x][y] < h) {
                        water += h - heightMap[x][y];
                    }
                    pq.push({max(heightMap[x][y], h), x, y});
                }
            }
        }

        return water;
    }
};
// Time Complexity O(m * n * log(m*n))
// space Complexity O(m * n)