class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n);
        for(auto &e:dislikes){
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        vector<int>col(n, -1);
        for(int i=0; i<n; i++){
            if(col[i]==-1){
                queue<int>q;
                q.push(i);
                col[i]=0;
                while(!q.empty()){
                    int node = q.front();q.pop();
                    for(int nei:adj[node]){
                        if(col[nei]==-1){
                            col[nei]=!col[node];
                            q.push(nei);
                        }
                        else if(col[node]==col[nei])return false;
                    }
                }
            }
        }
        return true;
    }
};