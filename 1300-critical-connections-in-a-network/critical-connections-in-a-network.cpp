class Solution {
private:
    vector<int>vis, tin, low;
    vector<vector<int>>bridges;
    int timer = 1;
    void dfs(int node, int parent,  vector<int>adj[]){
        vis[node]=1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto nei:adj[node]){
            if(nei==parent)continue;
            if(vis[nei]==0){
                dfs(nei, node, adj);
                low[node] = min(low[node], low[nei]);
                if(low[nei] > tin[node]){
                    bridges.push_back({node, nei});
                }
            }
            else{
                low[node] = min(low[node], low[nei]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto connection:connections){
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        vis.resize(n, 0);
        tin.resize(n, 0);
        low.resize(n, 0);
        dfs(0, -1, adj);
        return bridges;
    }
};