class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        vector<vector<int>>dist(r, vector<int>(c,1e9));

        pq.push({0, {0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int diff = pq.top().first;
            auto [i, j] = pq.top().second;
            pq.pop();
            if(i==r-1 && j==c-1)return diff;

            if(i-1>=0){
                int temp = max(diff, abs(heights[i][j]-heights[i-1][j]));
                if(dist[i-1][j]>temp){
                    dist[i-1][j]=temp;
                    pq.push({temp, {i-1, j}});
                }
            }
            if(j-1>=0){
                int temp = max(diff, abs(heights[i][j]-heights[i][j-1]));
                if(dist[i][j-1]>temp){
                    dist[i][j-1]=temp;
                    pq.push({temp, {i, j-1}});
                }
            }
            if(i+1<r && abs(heights[i][j]-heights[i+1][j])<dist[i+1][j]){
                int temp = max(diff,abs(heights[i][j]-heights[i+1][j]));
                if(dist[i+1][j]>temp){
                    dist[i+1][j]=temp;
                    pq.push({temp, {i+1, j}});
                }
            }
            if(j+1<c && abs(heights[i][j]-heights[i][j+1])<dist[i][j+1]){
                int temp = max(diff, abs(heights[i][j]-heights[i][j+1]));
                if(dist[i][j+1]>temp){
                    dist[i][j+1]=temp;
                    pq.push({temp, {i, j+1}});
                }
            }
            
        }
        return 0;
    }
};