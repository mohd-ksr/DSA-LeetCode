class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        int n = nums.size();
        vector<vector<int>>adj(n);
        for(int i=0; i<n; i++){
            if(nums[i]==0)continue;
            if(i-nums[i] >= 0) adj[i].push_back(i-nums[i]);
            if(i+nums[i] < n) adj[i].push_back(i+nums[i]);
        }
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(start);
        vis[start]=true;
        while(!q.empty()){
            int node = q.front();q.pop();
            if(nums[node]==0)return true;
            for(auto nei:adj[node]){
                if(!vis[nei]){
                    vis[nei]=true;
                    q.push(nei);
                }
            }
        }
        return false;
    }
};