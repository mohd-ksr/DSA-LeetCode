class Solution {
private:
    vector<vector<int>>r(vector<vector<int>>&mat){
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>>ans(r, vector<int>(c));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ans[j][r-i-1] = mat[i][j];
            }
        }
        return ans;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        matrix = r(matrix);
    }
};