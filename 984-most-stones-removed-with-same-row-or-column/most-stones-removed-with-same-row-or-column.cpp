class DSU{
public:
    vector<int>parent,size,rank;
    DSU(int n){
        rank.resize(n+1, 0);
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int r=0;
        int c=0;
        for(auto it:stones){
            r = max(r, it[0]);
            c = max(c, it[1]);
        }

        DSU ds(r+c+1);
        unordered_map<int, int>stoneNods;
        for(auto it:stones){
            int nodeR = it[0];
            int nodeC = it[1]+r+1;
            ds.unionBySize(nodeR, nodeC);
            stoneNods[nodeR]=1;
            stoneNods[nodeC]=1;
        }

        int cnt=0;
        for(auto it:stoneNods){
            if(ds.findUlpParent(it.first)==it.first)cnt++;
        }
        return n-cnt;
    }
};








