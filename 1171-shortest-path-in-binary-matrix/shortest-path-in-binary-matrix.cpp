class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        queue<pair<int, int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int ans=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [i, j]=q.front(); q.pop();
                if(i==n-1 && j==n-1)return ans+1;
                if(i-1>=0 && grid[i-1][j]==0){
                    grid[i-1][j]=1;
                    q.push({i-1, j});
                }

                if(j-1>=0 && grid[i][j-1]==0){
                    grid[i][j-1]=1;
                    q.push({i, j-1});
                }

                if(i+1<n && grid[i+1][j]==0){
                    grid[i+1][j]=1;
                    q.push({i+1, j});
                }
                if(j+1<n && grid[i][j+1]==0){
                    grid[i][j+1]=1;
                    q.push({i, j+1});
                }

                if(i-1>=0 && j-1>=0 && grid[i-1][j-1]==0){
                    grid[i-1][j-1]=1;
                    q.push({i-1, j-1});
                }

                if(i+1<n && j+1<n && grid[i+1][j+1]==0){
                    grid[i+1][j+1]=1;
                    q.push({i+1, j+1});
                }
                if(i-1>=0 && j+1<n && grid[i-1][j+1]==0){
                    grid[i-1][j+1]=1;
                    q.push({i-1, j+1});
                }
                if(i+1<n && j-1>=0 && grid[i+1][j-1]==0){
                    grid[i+1][j-1]=1;
                    q.push({i+1, j-1});
                }
            }
            ans++;
        }
        return -1;
    }
};