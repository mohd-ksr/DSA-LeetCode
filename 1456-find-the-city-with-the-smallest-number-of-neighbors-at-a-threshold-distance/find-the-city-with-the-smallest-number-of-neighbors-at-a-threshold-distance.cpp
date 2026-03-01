class Solution {
public:
    const int inf = 1e9;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n, vector<int>(n, inf));
        for(auto &e:edges){
            dist[e[0]][e[1]]=e[2];
            dist[e[1]][e[0]]=e[2];
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k]!=inf && dist[k][j]!=inf){
                        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                    }
                }
            }
        }

        int ans = -1;
        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(i==j)continue;
                if(dist[i][j] <= distanceThreshold)count++;
            }
            if(mini>=count){
                mini=count;
                ans=i;
            }
        }
        return ans;
    }
};