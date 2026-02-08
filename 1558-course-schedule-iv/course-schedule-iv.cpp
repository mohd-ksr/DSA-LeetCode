class Solution {
private:    
    bool bfs(int src, int dest, vector<vector<int>>&adj, int numCourses){
        vector<bool>vis(numCourses, false);
        queue<int>q;
        q.push(src);
        vis[src]=true;
        while(!q.empty()){
            int node = q.front(); q.pop();
            if(node==dest)return true;
            for(auto nei:adj[node]){
                if(!vis[nei])q.push(nei);
            }
        }
        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // vector<vector<int>>adj(numCourses);
        vector<vector<bool>>mapp(numCourses, vector<bool>(numCourses, false));
        for(auto &e:prerequisites){
            // adj[e[0]].push_back(e[1]);
            mapp[e[0]][e[1]]=true;
        }
        for(int k=0; k<numCourses; k++){
            for(int i=0; i<numCourses; i++){
                for(int j=0; j<numCourses; j++){
                    mapp[i][j] = mapp[i][j] || (mapp[i][k] && mapp[k][j]);
                }
            }
        }
        vector<bool>ans;
        for(auto &q:queries){
            ans.push_back(mapp[q[0]][q[1]]);
        }
        return ans;
    }
};