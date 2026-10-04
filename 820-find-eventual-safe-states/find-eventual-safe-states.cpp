class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>adj[n];
        vector<int>id(n, 0);
        for(int u=0; u<n; u++){
            for(auto v:graph[u]){
                adj[v].push_back(u);
                id[u]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(id[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto nei:adj[node]){
                id[nei]--;
                if(id[nei]==0)q.push(nei);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};