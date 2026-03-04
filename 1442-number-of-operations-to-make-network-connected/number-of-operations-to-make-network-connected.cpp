class DSU{
public:
    vector<int>parent, rank;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0; i<n; i++)parent[i]=i;
    }

    int findUpar(int node){
        if(parent[node]==node)return node;
        return parent[node]=findUpar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
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
        if(connections.size() < n-1) return -1;

        DSU ds(n);
        for(auto &con:connections){
            ds.unionByRank(con[0], con[1]);
        }

        int ans = 0;
        for(int i=0; i<ds.parent.size(); i++){
            if(ds.parent[i]==i)ans++;
        }
        return ans-1;
    }
};