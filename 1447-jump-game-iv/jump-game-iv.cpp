class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>>mapp;
        for(int i=0; i<n; i++){
            mapp[nums[i]].push_back(i);
        }

        // vector<vector<int>>adjList(n);
        // for(int i=0; i<n; i++){
        //     if(i-1>=0)adjList[i].push_back(i-1);
        //     if(i+1<n)adjList[i].push_back(i+1);
        //     for(auto e:mapp[nums[i]]){
        //         if(e!=i-1 && e!=i+1 && e!=i)adjList[i].push_back(e);
        //     }
        // }

        // for(int i=0; i<n; i++){
        //     for(auto v:adjList[i])cout<<v<<" ";
        //     cout<<endl;
        // }

        vector<bool>vis(n, false);
        queue<int>q;
        q.push(0);
        vis[0]=true;
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int u = q.front();q.pop();
                if(u == n-1)return ans;
                vector<int>&list = mapp[nums[u]];
                list.push_back(u-1); list.push_back(u+1);
                for(auto v:list){
                    if(v>=0 && v<n && !vis[v]){
                        vis[v]=true;
                        q.push(v);
                    }
                }
                list.clear();
            }
            ans++;
        }
        return n-1;
    }
};