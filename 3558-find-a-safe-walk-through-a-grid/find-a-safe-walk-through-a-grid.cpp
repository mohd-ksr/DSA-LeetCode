// class Solution {
// public:
//     bool findSafeWalk(vector<vector<int>>& grid, int health) {
//         int n = grid.size();
//         int m = grid[0].size();
//         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
//         pq.push({grid[0][0], 0, 0});
//         grid[0][0]=-1;
//         while(!pq.empty()){
//             auto [val, i, j]=pq.top();
//             pq.pop();
//             if(val==1)health--;
//             if(health<0)return false;
//             if(i==n-1 && j==m-1)return true;

//             int dx[] = {-1, 0, 1, 0};
//             int dy[] = {0, -1, 0, 1};
//             for(int d=0; d<4; d++){
//                 int ni = i+dx[d];
//                 int nj = j+dy[d];
//                 if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]!=-1){
//                     pq.push({grid[ni][nj], ni, nj});
//                     grid[ni][nj]=-1;
//                 }
//             }
//         }
//         return false;
//     }
// };



class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, -1));
        int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;
        pq.emplace(grid[0][0], 0, 0);
        while (!pq.empty()) {
            auto [val, cx, cy] = pq.top();
            pq.pop();
            if (dis[cx][cy] >= 0) {
                continue;
            }
            dis[cx][cy] = val;
            for (int k = 0; k < 4; k++) {
                int nx = cx + dirs[k][0];
                int ny = cy + dirs[k][1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n ||
                    dis[nx][ny] >= 0) {
                    continue;
                }
                pq.emplace(val + grid[nx][ny], nx, ny);
            }
        }

        return dis[m - 1][n - 1] < health;
    }
};