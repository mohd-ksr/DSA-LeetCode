class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>adj[n];
        vector<int>inDeg(n,0);
        for(int i=0; i<n; i++){
            for(int nei:graph[i]){
                adj[nei].push_back(i);
                inDeg[i]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(inDeg[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nei:adj[node]){
                inDeg[nei]--;
                if(inDeg[nei]==0){
                    q.push(nei);
                }
            }
            ans.push_back(node);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};