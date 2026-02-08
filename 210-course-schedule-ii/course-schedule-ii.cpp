class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inDeg(numCourses, 0);
        for(auto &e:prerequisites){
            adj[e[1]].push_back(e[0]);
            inDeg[e[0]]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(inDeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(int nei:adj[node]){
                inDeg[nei]--;
                if(inDeg[nei]==0)q.push(nei);
            }
            ans.push_back(node);
        }

        if(ans.size() == numCourses) return ans;
        else return {};
    }
};