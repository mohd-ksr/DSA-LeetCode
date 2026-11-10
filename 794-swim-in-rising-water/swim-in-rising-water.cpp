class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>vis(n, vector<int>(n, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        int time = 0;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0]=1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        while(!pq.empty()){
            int val = pq.top().first;
            auto [i, j] = pq.top().second;
            pq.pop();
            time = max(time, val);
            if(i==n-1 && j==n-1)return time;
            for(int k=0; k<4; k++){
                int ni = i+dx[k];
                int nj = j+dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<n && vis[ni][nj]==0){
                    vis[ni][nj]=1;
                    pq.push({grid[ni][nj], {ni, nj}});
                }
            }
        }
        return time;
    }
};