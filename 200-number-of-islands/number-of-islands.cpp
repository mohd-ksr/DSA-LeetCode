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
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        DSU ds(r*c);
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]=='1'){
                    int node = c*i+j;
                    for(int k=0; k<4; k++){
                        int ni = i+dx[k];
                        int nj = j+dy[k];
                        if(ni>=0 && ni<r && nj>=0 && nj<c && grid[ni][nj]=='1'){
                            int nei = c*ni+nj;
                            ds.unionBySize(node, nei);
                        }
                    }
                }
            }
        }

        unordered_set<int>st;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]=='1'){
                    int node = c*i+j;
                    st.insert(ds.findUlp(node));
                }
            }
        }
        return st.size();
    }
};