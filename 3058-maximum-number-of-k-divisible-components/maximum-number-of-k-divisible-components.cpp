class Solution {
private:
    int dfs(int u, int p, vector<vector<int>>&adj, vector<int>& values, int &k, int &c){
        int sum = 0;
        for(int v:adj[u]){
            if(v==p)continue;
            sum+=dfs(v,u,adj,values,k,c);
            sum%=k;
        }
        sum+=values[u];
        sum%=k;
        if(sum==0)c++;
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int c=0;
        dfs(0,-1,adj,values,k,c);
        return c;
    }
};
// Time Complexity O(n)
// Space Complexity O(n)