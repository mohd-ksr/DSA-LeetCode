class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>>q;
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        q.push({0, 0});
        grid[0][0]=1;
        // (i+1, j) (i, j+1) (i-1, j) (i, j-1) (i+1, j+1) (i+1, j-1) (i-1, j+1) (i-1, j-1)
        int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
        int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
        int ans = 1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [i, j] = q.front();
                q.pop();
                if(i==n-1 && j==n-1)return ans;
                for(int k=0; k<8; k++){
                    int ni = i+dx[k];
                    int nj = j+dy[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==0){
                        q.push({ni, nj});
                        grid[ni][nj]=1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};