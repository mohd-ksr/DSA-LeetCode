class Solution {
private:
    int r,c;
    int dfs(vector<vector<int>>&grid, int i, int j, int &key){
        if(i<0 || i>=r || j<0 || j>=c || grid[i][j]!=1)return 0;
        grid[i][j]=key;
        return 1 + dfs(grid, i-1, j, key) + dfs(grid, i, j-1, key) + dfs(grid, i+1, j, key) + dfs(grid, i, j+1, key);
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
                    mapp[key]=dfs(grid, i, j, key);
                    key++;
                }
            }
        }

        if(mapp.size()==0)return 1;
        if(mapp.size()==1){
            return (mapp[2]==r*c? mapp[2]:mapp[2]+1);
        }

        int ans = 1;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==0){
                    unordered_set<int>st;
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

                    int temp = 1;
                    for(auto it:st){
                        temp+=mapp[it];
                    }
                    ans = max(ans, temp);
                }
            }
        }

        return ans;
    }
};