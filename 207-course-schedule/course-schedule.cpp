class Solution {
private:
    bool dfs(int node,  vector<vector<int>>&adjList, vector<int>&vis, vector<int>&pathVis){
        vis[node]=1;
        pathVis[node]=1;

        for(int nei:adjList[node]){
            if(!vis[nei]){
                if(dfs(nei, adjList, vis, pathVis))return true;
            }
            else if(pathVis[nei]==1)return true;
        }

        pathVis[node]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjList(numCourses);
        for(auto e:prerequisites){
            adjList[e[1]].push_back(e[0]);
        }

        vector<int>vis(numCourses, 0), pathVis(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){ 
                if(dfs(i, adjList, vis, pathVis))return false;
            }
        }
        return true;
    }
};