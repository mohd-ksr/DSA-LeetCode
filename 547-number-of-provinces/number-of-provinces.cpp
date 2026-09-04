class Solution {
private:
    vector<int>vis;
    void dfs(int node, vector<vector<int>>& isConnected){
        if(vis[node])return;
        vis[node] = true;
        for(int i=0; i<isConnected.size(); i++){
            if(isConnected[node][i]==1){
                dfs(i, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vis.resize(n, false);
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, isConnected);
                ans++;
            }
        }
        return ans;
    }
};