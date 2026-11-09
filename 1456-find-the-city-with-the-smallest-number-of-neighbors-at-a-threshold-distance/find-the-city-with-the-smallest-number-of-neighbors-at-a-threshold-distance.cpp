class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int inf = 1e9;
        vector<vector<int>>mat(n, vector<int>(n, inf));
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }
        for(int i = 0; i < n; i++) {
            mat[i][i] = 0;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(mat[i][k]!=inf && mat[k][j]!=inf){
                        mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                    }
                }
            }
        }
        vector<int>reachableCount(n, inf);
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(i != j  && mat[i][j] <= distanceThreshold)count++;
            }
            reachableCount[i] = count;
        }
        int mini = *min_element(reachableCount.begin(), reachableCount.end());
        for(int i=n-1; i>=0; i--){
            if(reachableCount[i]==mini)return i;
        }
        return n-1;
    }
};