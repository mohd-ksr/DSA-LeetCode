class Solution {
private:
    vector<vector<int>>ans;
    vector<int>tin, low, vis;
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>>&adj){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(int nei:adj[node]){
            if(nei==parent)continue;
            if(vis[nei]==0){
                dfs(nei, node, adj);
                if(low[nei] > tin[node]){
                    ans.push_back({nei, node});
                }
            }
            low[node] = min(low[node], low[nei]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto conn:connections){
            int u = conn[0];
            int v = conn[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vis.resize(n, 0);
        tin.resize(n, 0);
        low.resize(n, 0);
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                dfs(i, -1, adj);
            }
        }
        return ans;
    }
};