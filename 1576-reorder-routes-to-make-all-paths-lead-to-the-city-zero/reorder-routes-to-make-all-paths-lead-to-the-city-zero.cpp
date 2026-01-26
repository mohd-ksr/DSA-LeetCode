class Solution {
private:
    void dfs( vector<vector<pair<int, int>>>&adjList, int node, int parent,  int &count){
        for(auto [nei, sign]:adjList[node]){
            if(nei!=parent){
                count+=sign;
                dfs(adjList, nei, node, count);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>>adjList(n);
        for(auto &e:connections){
            adjList[e[0]].push_back({e[1], 1});
            adjList[e[1]].push_back({e[0], 0});
        }

        int count = 0;
        dfs(adjList, 0, -1, count);
        return count;
    }
};