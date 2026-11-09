class Solution {
private:
    int n;
    int dfs(int i, int j, int &key, vector<vector<int>>& grid){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1)return 0;
        grid[i][j]=key;
        return 1 + dfs(i+1, j, key, grid) + dfs(i, j+1, key, grid) + dfs(i-1, j, key, grid) + dfs(i, j-1, key, grid);
    }    
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int key = 2;
        unordered_map<int, int>mapp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    mapp[key] = dfs(i, j, key, grid);
                    key++;
                }
            }
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    set<int>st;
                    for(int k=0; k<4; k++){
                        int ni = i+dx[k];
                        int nj = j+dy[k];
                        if(ni<n && ni>=0 && nj>=0 && nj<n && grid[ni][nj]!=0){
                            st.insert(grid[ni][nj]);
                        }
                    }
                    int sum = 0;
                    for(auto it:st){
                        sum+=mapp[it];
                    }
                    ans = max(ans, sum+1);
                }
            }
        }
        return ans==0?n*n:ans;
    }
};