class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
            > pq;
        vector<vector<int>>dist(r, vector<int>(c, 1e9));
        pq.push({0, {0,0}});
        dist[0][0] = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        while(!pq.empty()){
            int diff = pq.top().first;
            auto [i, j] = pq.top().second;
            pq.pop();
            if(i==r-1 && j==c-1)return diff;
            for(int k=0; k<4; k++){
                int ni = i+dx[k];
                int nj = j+dy[k];
                if(ni>=0 && ni<r && nj>=0 && nj<c){
                    int temp = max(diff, abs(mat[i][j]-mat[ni][nj]));
                    if(temp < dist[ni][nj]){
                        dist[ni][nj] = temp;
                        pq.push({temp, {ni, nj}});
                    }
                }
            }
        }
        return -1;
    }
};