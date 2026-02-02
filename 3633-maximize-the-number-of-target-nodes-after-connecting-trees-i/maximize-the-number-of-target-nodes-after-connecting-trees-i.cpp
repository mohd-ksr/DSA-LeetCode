class Solution {
private:    
    int bfs(vector<vector<int>>&adj, int src, int k){
        if(k<0)return 0;
        int ans = 1;
        queue<pair<int, int>>q;
        q.push({src, -1});
        for(int i=0; i<k; i++){
            int size = q.size();
            while(size--){
                auto [node, parent] = q.front(); q.pop();
                for(auto v:adj[node]){
                    if(v!=parent){
                        ans++;
                        q.push({v, node});
                    }
                }
            }
        }
        return ans;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;

        vector<vector<int>>adj1(n),adj2(m);
        for(auto e:edges1){
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }

        for(auto e:edges2){
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        vector<int>v1(n);
        int maxIn2 = INT_MIN;
        for(int i=0 ;i<m; i++){
            maxIn2 = max(maxIn2, bfs(adj2, i, k-1));
        }
        for(int i=0; i<n; i++){
            v1[i]=bfs(adj1, i, k)+maxIn2;
        }

        return v1;
    }
};