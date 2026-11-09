class DSU{
private:
    vector<int>parent, rank, size;
public:
    DSU(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++)parent[i] = i;
    }
    int findUlp(int node){
        if(node == parent[node])return node;
        return parent[node] = findUlp(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] = size[ulp_v];
        }
    }
    void unionByRank(int u, int v){
        int ulp_u = findUlp(u);
        int ulp_v = findUlp(v);
        if(ulp_u == ulp_v)return;
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
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)return -1;
        DSU ds(n);
        for(auto connection:connections){
            ds.unionByRank(connection[0], connection[1]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(ds.findUlp(i)==i)ans++;
        }
        return ans-1;
    }
};