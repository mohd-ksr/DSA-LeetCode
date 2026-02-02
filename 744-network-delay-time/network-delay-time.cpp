class Solution {
private:
    const int inf = 1e7+1;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adjList(n+1);
        for(auto &t:times){
            adjList[t[0]].push_back({t[2], t[1]});
        }

        vector<int>dist(n+1, inf);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto [d, u] = pq.top(); pq.pop();

            if(d>dist[u])continue;

            for(auto [w, v]: adjList[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u]+w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1; i<=n; i++){
            if(dist[i]==inf)return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};