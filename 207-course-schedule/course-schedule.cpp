class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int>adj[n];
        for(auto e:prerequisites){
            adj[e[1]].push_back(e[0]);
        }
        vector<int>id(n, 0);
        for(int i=0; i<n; i++){
            for(auto nei:adj[i]){
                id[nei]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(id[i]==0)q.push(i);
        }
        int ans = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans++;
            for(auto nei:adj[node]){
                id[nei]--;
                if(id[nei]==0)q.push(nei);
            }
        }
        return ans==n;
    }
};


