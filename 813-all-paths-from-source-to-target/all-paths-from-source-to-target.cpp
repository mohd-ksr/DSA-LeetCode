class Solution {
private:
    vector<vector<int>>ans;
    int n;
    void solve(int node, vector<vector<int>>& adj, vector<int>cand){
        cand.push_back(node);
        if(node==n-1){
            ans.push_back(cand);
        }
        for(auto nei:adj[node]){
            solve(nei, adj, cand);
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        solve(0, graph, {});
        return ans;
    }
};