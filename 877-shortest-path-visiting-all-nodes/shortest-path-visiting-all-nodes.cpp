class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int finalMask = (1<<n)-1;

        queue<pair<int, int>>q;
        vector<vector<int>>dist(n, vector<int>(1<<n, -1));

        for(int i=0; i<n; i++){
            int mask = (1<<i);
            q.push({i, mask});
            dist[i][mask] = 0;
        }

        while(!q.empty()){
            auto [node, mask] = q.front(); q.pop();

            int d = dist[node][mask];
            if(mask==finalMask) return d;

            for(auto n:graph[node]){
                int newMask = mask | (1<<n);
                if(dist[n][newMask]==-1){
                    dist[n][newMask]=d+1;
                    q.push({n, newMask});
                }
            }
        }
        return -1;
    }
};
// Time Complexity O(n² * 2^n)
// Space Complexity O(n² * 2^n)






