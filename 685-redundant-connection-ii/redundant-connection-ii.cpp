class DSU{
private:
    vector<int>parent,rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
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
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1, -1);
        vector<int>cand1;
        vector<int>cand2;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            if(parent[v] == -1)parent[v] = u;
            else{
                cand1 = {parent[v], v};
                cand2 = {u, v};
                break;
            }
        }
        DSU ds(n);
        vector<int>ans;
        if(cand1.size()==0){
            for(auto edge:edges){
                int u = edge[0];
                int v = edge[1];
                if(ds.findUlp(u) == ds.findUlp(v))ans = edge;
                ds.unionByRank(u, v);
            }
        }
        else{
            bool ok = true;
            for(auto edge:edges){
                int u = edge[0];
                int v = edge[1];
                if(u==cand2[0] && v==cand2[1])continue;
                if(ds.findUlp(u) == ds.findUlp(v)){
                    ok = false;
                    break;
                }
                ds.unionByRank(u, v);
            }
            if(ok)ans = cand2;
            else ans = cand1; 
        }
        return ans;
    }
};