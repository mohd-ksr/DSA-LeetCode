class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto f:flights){
            adj[f[0]].push_back({f[1], f[2]}); // u -> {{v,w}...}
        }

        queue<pair<int, pair<int, int>>>pq; // (stops, {node, dist})
        vector<int>dist(n,1e9);
        pq.push({0, {src, 0}});
        dist[src]=0;
        while(!pq.empty()){
            int s = pq.front().first;
            auto [node, d] = pq.front().second;
            pq.pop();
            if(s>k)continue;
            for(auto [v, w]:adj[node]){
                if(d+w < dist[v] && s<=k){
                    dist[v]=d+w;
                    pq.push({s+1, {v, dist[v]}});
                }
            }
        }
        return (dist[dst]==1e9?-1:dist[dst]);
    }
};