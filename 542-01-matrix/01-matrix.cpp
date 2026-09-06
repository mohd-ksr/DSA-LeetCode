class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>>q;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                }
                else{
                    mat[i][j]=-1;
                }
            }
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int ni = i+dx[k];
                int nj = j+dy[k];
                if(ni>=0 && ni<mat.size() && nj>=0 && nj<mat[0].size() && mat[ni][nj]==-1){
                    mat[ni][nj] = mat[i][j]+1;
                    q.push({ni, nj});
                }
            }
        }
        return mat;
    }
};