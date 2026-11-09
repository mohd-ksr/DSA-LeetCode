class DSU{
private:
    vector<int>size, parent;
public:
    DSU(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUlp(int node){
        if(parent[node]==node)return node;
        return parent[node] = findUlp(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);
        if(ulp_u == ulp_v) return; 
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int getSize(int node){
        if(node<0 || node>size.size())return 0;
        return size[node];
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    int node = n*i+j;
                    for(int k=0; k<4; k++){
                        int ni = i+dx[k];
                        int nj = j+dy[k];
                        if(ni >=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==1){
                            int nei = n*ni+nj;
                            ds.unionBySize(node, nei);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    set<int>st;
                    for(int k=0; k<4; k++){
                        int ni = i+dx[k];
                        int nj = j+dy[k];
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==1){
                            int nei = n*ni+nj;
                            st.insert(ds.findUlp(nei));
                        }
                    }
                    int sum = 0;
                    for(auto node:st){
                        sum += ds.getSize(node);
                    }
                    ans = max(ans, sum+1);
                }
            }
        }
        return ans==0 ? n*n : ans;
    }
};