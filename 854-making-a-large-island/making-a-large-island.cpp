class DSU{
// private:
//     vector<int>parent,size;
public:
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    
    int findUlpParent(int node){
        if(node==parent[node])return node;
        return parent[node]=findUlpParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUlpParent(u);
        int ulp_v = findUlpParent(v);
        if(ulp_u==ulp_v)return;
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);

        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c]==0)continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};

                for(int i=0; i<4; i++){
                    int adjR = r+dr[i];
                    int adjC = c+dc[i];

                    if(adjR>=0 && adjR<n && adjC>=0 && adjC<n && grid[adjR][adjC]==1){
                        int nodeN = r*n+c;
                        int adjNodeN = adjR*n+adjC;
                        ds.unionBySize(nodeN, adjNodeN);
                    }
                }
            }
        }
        int ans = 0;
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c]==1)continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                unordered_set<int>compos;
                for(int i=0; i<4; i++){
                    int adjR = r+dr[i];
                    int adjC = c+dc[i];

                    if(adjR>=0 && adjR<n && adjC>=0 && adjC<n && grid[adjR][adjC]==1){
                        int adjNodeN = adjR*n+adjC;
                        compos.insert(ds.findUlpParent(adjNodeN));
                    }
                }
                int totalSize = 1;
                for(auto comp:compos){
                    totalSize+=ds.size[comp];
                }
                ans = max(ans, totalSize);
            }
        }
        return ans==0?n*n:ans;
    }
};


















