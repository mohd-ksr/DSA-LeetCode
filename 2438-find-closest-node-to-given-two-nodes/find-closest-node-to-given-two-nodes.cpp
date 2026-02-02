class Solution {
private:
    const int inf = 1e9+7;
    void bfs(vector<int>& edges, int n, int src, vector<int>&dist){
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(src);
        dist[src]=0;
        vis[src]=true;
        while(!q.empty()){
            int node = q.front(); q.pop();
            int v = edges[node];
            if(v!=-1 && !vis[v]){
                dist[v]=dist[node]+1;
                vis[v]=true;
                q.push(v);
            }
            
        }

    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>distFrom1(n, inf);
        vector<int>distFrom2(n, inf);
        bfs(edges, n, node1, distFrom1);
        bfs(edges, n, node2, distFrom2);
        
        int ans = -1;
        int mini = INT_MAX;

        for(int i=0; i<n; i++){
            if(distFrom1[i]!=inf && distFrom2[i]!=inf){
                int temp = max(distFrom1[i], distFrom2[i]);
                if(mini > temp){
                    mini = temp;
                    ans=i;
                }

            }
        }

        return ans;
    }
};