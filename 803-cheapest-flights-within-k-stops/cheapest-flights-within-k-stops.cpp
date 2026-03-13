class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto f:flights){
            int u = f[0];
            int v = f[1];
            int w = f[2];
            adj[u].push_back({v, w});
        }

        vector<int>dist(n, 1e9);
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {src, 0}});

        while(!q.empty()){
            int s = q.front().first;
            auto [node,d] = q.front().second;
            q.pop();
            if(s>k)continue;

            for(auto [v, w]:adj[node]){
                if(d+w < dist[v] && s<=k){
                    dist[v] = d+w,
                    q.push({s+1, {v, d+w}});
                }
            }
        }
        return dist[dst]==1e9? -1:dist[dst];
    }
};