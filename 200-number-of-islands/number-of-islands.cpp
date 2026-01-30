class Solution {
private:
    int r,c;
    void bfs(int si, int sj, vector<vector<char>>& grid){
        queue<pair<int, int>>q;
        q.push({si, sj});
        grid[si][sj]='0';
        while(!q.empty()){
            auto [i, j]=q.front(); q.pop();
            if(i-1>=0 && grid[i-1][j]=='1'){
                grid[i-1][j]='0';
                q.push({i-1, j});
            }
            if(j-1>=0 && grid[i][j-1]=='1'){
                grid[i][j-1]='0';
                q.push({i, j-1});
            }
            if(i+1<r && grid[i+1][j]=='1'){
                grid[i+1][j]='0';
                q.push({i+1, j});
            }
            if(j+1<c && grid[i][j+1]=='1'){
                grid[i][j+1]='0';
                q.push({i, j+1});
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        this-> r = grid.size();
        this-> c = grid[0].size();

        int ans=0;
        queue<pair<int, int>>q;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]=='1'){
                    bfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};