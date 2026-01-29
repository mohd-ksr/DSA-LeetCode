class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        queue<int>q;
        for(int i=0; i<n; i++){
            if(color[i]!=-1)continue;
            q.push(i);
            color[i]=0;
            while(!q.empty()){
                int node = q.front();q.pop();
                for(int nei:graph[node]){
                    if(color[nei]==-1){
                        color[nei]=!color[node];
                        q.push(nei);
                    }
                    else if(color[node]==color[nei])return false;
                }
            }
        }
        return true;
    }
};