class Solution {
private:
    int r;
    int c;
    void dfs(int i, int j, vector<vector<int>> &image, int color, int srcColor){
        if(i<0 || i>=r || j<0 || j>=c)return;
        if(image[i][j]!=srcColor)return;
        image[i][j]=color;
        dfs(i-1, j, image, color, srcColor);
        dfs(i+1, j, image, color, srcColor);
        dfs(i, j-1, image, color, srcColor);
        dfs(i, j+1, image, color, srcColor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int srcColor = image[sr][sc];
        if(color==srcColor)return image;
        r = image.size();
        c = image[0].size();
        dfs(sr, sc, image, color, srcColor);
        return image;
    }
};
// Time Complexity O(m*n)