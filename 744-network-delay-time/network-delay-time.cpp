class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto it:times){
            int u = it[0]-1;
            int v = it[1]-1;
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int ,int>>>pq;
        vector<int>dist(n, 1e9);
        pq.push({0, k-1});
        dist[k-1]=0;
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            for(auto [nei, wt]:adj[node]){
                if(d + wt < dist[nei]){
                    dist[nei] = d+wt;
                    pq.push({dist[nei], nei});
                }
            }
        }
        int ans = INT_MIN;
        for(auto d:dist){
            if(d==1e9)return -1;
            ans = max(ans, d);
        }
        return ans;
    }
};