class Solution {
private:    
    void dfs(vector<vector<int>>&adjList, int u,  vector<char>&vis){
        vis[u]='1';
        for(auto v:adjList[u]){
            if(vis[v]=='0')dfs(adjList, v, vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>>adjList(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        vector<char>vis(n,'0');
        int ans = 0;
        for(int i=0; i<n; i++){
            if(vis[i]=='0'){
                ans++;
                dfs(adjList, i, vis);
            }
        }
        return ans;
    }
};