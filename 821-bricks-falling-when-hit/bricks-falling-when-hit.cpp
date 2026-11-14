class DSU{
private:
    vector<int>parent,rank,size;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    int findUlp(int node){
        if(parent[node]==node)return node;
        return parent[node] = findUlp(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);

        if(ulp_u == ulp_v)return ;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);
        if(ulp_u == ulp_v)return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    int getSize(int node){
        return size[findUlp(node)];
    }
};
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int r = grid.size();
        int c = grid[0].size();
        int roof = r*c;
        DSU ds(r*c);
        vector<vector<int>> temp = grid;
        for(auto hit:hits){
            temp[hit[0]][hit[1]]=0;
        }
        for(int j=0; j<c; j++){
            if(temp[0][j]==0)continue;
            int node = j;
            ds.unionBySize(node, roof);
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(temp[i][j]==0)continue;
                int node = i*c+j;
                for(int k=0; k<4; k++){
                    int ni = i+dx[k];
                    int nj = j+dy[k];
                    if(ni>=0 && ni<r && nj>=0 && nj<c && temp[ni][nj]==1){
                        int nei = ni*c+nj;
                        ds.unionBySize(node, nei);
                    }
                }
            }
        }
        int n = hits.size();
        vector<int>ans(n);
        for(int h=n-1; h>=0; h--){
            int i = hits[h][0];
            int j = hits[h][1];
            if(grid[i][j]==0){
                ans[h]=0;
                continue;
            }
            int before = ds.getSize(roof);
            int node = i*c + j;
            if(i == 0){
                ds.unionBySize(node, roof);
            }
            temp[i][j] = 1;
            for(int k=0; k<4; k++){
                int ni = i+dx[k];
                int nj = j+dy[k];
                if(ni>=0 && ni<r && nj>=0 && nj<c && temp[ni][nj]==1){
                    int nei = ni*c+nj;
                    ds.unionBySize(node, nei);
                }
            }
            int after = ds.getSize(roof);
            ans[h] = max(0, after-before-1);
        }
        return ans;
    }
};