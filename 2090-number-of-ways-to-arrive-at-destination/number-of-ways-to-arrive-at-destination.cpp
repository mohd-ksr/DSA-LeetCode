class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, long long>>adj[n];
        const int mod = 1e9+7;
        for(auto road:roads){
            int u = road[0];
            int v = road[1];
            int time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>pq;
        vector<long long>dist(n, LLONG_MAX);
        vector<long long>ways(n, 0L);
        pq.push({0L, 0});
        dist[0]=0L;
        ways[0]=1L;
        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            if(time > dist[node]) continue;
            for(auto it:adj[node]){
                int nei = it.first;
                long long t = it.second;
                if(time + t < dist[nei]){
                    ways[nei] = ways[node];
                    dist[nei] = t+time;
                    pq.push({dist[nei], nei});
                }
                else if(time+t == dist[nei]){
                    ways[nei] = (ways[nei] + ways[node])%mod;
                }
            }
        }
        return (ways[n-1])%mod;
    }
};