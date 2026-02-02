class Solution {
private:
    int r,c;
    int dfs(int i, int j, vector<vector<int>>&grid, int &key){
        if(i<0 || i>=r || j<0 || j>=c || grid[i][j]!=1)return 0;
        grid[i][j]=key;
        return 1+dfs(i-1, j, grid, key)+dfs(i, j-1, grid, key)+dfs(i+1, j, grid, key)+dfs(i, j+1, grid, key);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        this->r = grid.size();
        this->c = grid[0].size();

        unordered_map<int, int>mapp;
        int key=2;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1){
                    mapp[key]=dfs(i, j, grid, key);
                    key++;
                }
            }
        }
        if(mapp.size()==0)return 1;

        if(mapp.size()==1){
            return( mapp[2]==r*c?mapp[2]:mapp[2]+1);
        }

        int ans = 1;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==0){
                    unordered_set<int>st;
                    int tempAns = 1;
                    if(i-1>=0 && grid[i-1][j]>1){
                        st.insert(grid[i-1][j]);
                    }
                    if(j-1>=0 && grid[i][j-1]>1){
                        st.insert(grid[i][j-1]);
                    }
                    if(i+1<r && grid[i+1][j]>1){
                        st.insert(grid[i+1][j]);
                    }
                    if(j+1<c && grid[i][j+1]>1){
                        st.insert(grid[i][j+1]);
                    }

                    for(auto id:st){
                        tempAns+=mapp[id];
                    }
                    ans = max(ans, tempAns);
                }
            }
        }

        return ans;
    }
};