class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor)return image;
        queue<pair<int, int>>q;
        q.push({sr, sc});
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        int srcColor = image[sr][sc];
        image[sr][sc]=-1;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int ni = i+dx[k];
                int nj = j+dy[k];
                if(ni>=0 && ni<image.size() && nj>=0 && nj<image[0].size() && image[ni][nj]==srcColor){
                    q.push({ni, nj});
                    image[ni][nj]=-1;
                }
            }
        }
        for(int i=0; i<image.size(); i++){
            for(int j=0; j<image[0].size(); j++){
                if(image[i][j]==-1)image[i][j]=newColor;
            }
        }
        return image;
    }
};