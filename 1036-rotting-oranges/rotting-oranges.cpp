class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int fresh = 0;
        queue<pair<int, int>>q;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]==1)fresh++;
            }
        }
        int ans = 0;
        while(!q.empty() && fresh){
            int size = q.size();
            for(int k=0; k<size; k++){
                auto [i, j] = q.front(); q.pop();
                if(i-1>=0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1, j});
                    fresh--;
                }
                if(j-1>=0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i, j-1});
                    fresh--;
                }
                if(i+1<r && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1, j});
                    fresh--;
                }
                if(j+1<c && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i, j+1});
                    fresh--;
                }
            }
            ans++;
        }
        return (fresh==0? ans:-1);
    }
};