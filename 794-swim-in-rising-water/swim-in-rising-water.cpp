class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({grid[0][0], 0, 0});
        while(!pq.empty()){
            auto temp = pq.top(); pq.pop();
            int time = temp[0];
            int i = temp[1];
            int j = temp[2];
            if(vis[i][j])continue;
            vis[i][j]=true;
            if(i==n-1 && j==n-1)return time;
            if(i-1>=0 && !vis[i-1][j]){
                pq.push({max(time,grid[i-1][j]), i-1, j});
            }
            if(j-1>=0 && !vis[i][j-1]){
                pq.push({max(time,grid[i][j-1]), i, j-1});
            }
            if(i+1<n && !vis[i+1][j]){
                pq.push({max(time,grid[i+1][j]), i+1, j});
            }
            if(j+1<n && !vis[i][j+1]){
                pq.push({max(time,grid[i][j+1]), i, j+1});
            }
        }
        return -1;
    }
};