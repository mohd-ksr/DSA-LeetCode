class Solution {
private:
    bool check(int start, vector<vector<int>>& graph, vector<int>&col){
        queue<int>q;
        q.push(start);
        col[start]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nei:graph[node]){
                if(col[nei]==-1){
                    col[nei] = !col[node];
                    q.push(nei);
                }
                else if(col[nei]==col[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>col(n, -1);
        for(int i=0; i<n; i++){
            if(col[i]==-1){
                if(check(i, graph, col)==false)return false;
            }
        }
        return true;
    }
};