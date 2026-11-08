class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        unordered_map<int, int>adj;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1){
                    int key = i*c + j;
                    adj[key] = 0;
                    for(int k=i+1; k<r; k++){
                        if(grid[k][j]==1){
                            adj[key]++;
                        }
                    }
                    for(int k=i-1; k>=0; k--){
                        if(grid[k][j]==1){
                            adj[key]++;
                        }
                    }
                    for(int k=j+1; k<c; k++){
                        if(grid[i][k]==1){
                            adj[key]++;
                        }
                    }
                    for(int k=j-1; k>=0; k--){
                        if(grid[i][k]==1){
                            adj[key]++;
                        }
                    }
                }
            }
        }
        
        int ans=0;
        for(auto it:adj){
            ans+=(it.second!=0);
        }
        return ans;
    }
};