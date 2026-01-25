class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>redAdj(n), blueAdj(n);
        for(auto &e:redEdges)redAdj[e[0]].push_back(e[1]);
        for(auto &e:blueEdges)blueAdj[e[0]].push_back(e[1]);

        int inf = 1e9;
        vector<vector<int>>dist(n, vector<int>(2, inf));
        dist[0][0] = dist[0][1] = 0;
        queue<pair<int, int>>q;
        q.push({0, 0});
        q.push({0, 1});
        while(!q.empty()){
            auto [node, color] = q.front(); q.pop();

            if(color==0){
                for(int n:blueAdj[node]){
                    if(dist[n][1]==inf){
                        dist[n][1] = dist[node][0]+1;
                        q.push({n, 1});
                    }
                }
            }
            else{
                for(int n:redAdj[node]){
                    if(dist[n][0]==inf){
                        dist[n][0] = dist[node][1]+1;
                        q.push({n, 0});
                    }
                }
            }
        }

        vector<int>ans(n, -1);
        for(int i=0; i<n; i++){
            int best = min(dist[i][0], dist[i][1]);
            if(best!=inf)ans[i]=best;
        }
        
        return ans;
    }
};
// Time Complexity O(n + R + B)
// Space Complexity O(n + R + B)