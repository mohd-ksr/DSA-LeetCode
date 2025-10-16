class Solution {
private:
    void dfs(int node, vector<vector<int>>&adj, vector<bool>&vis){
        if(vis[node])return;
        vis[node]=true;
        for(auto &v:adj[node]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>adj(isConnected.size());
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected.size(); j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool>vis(adj.size(), false);
        int ans=0;
        for(int i=0; i<vis.size(); i++){
            if(!vis[i]){
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};