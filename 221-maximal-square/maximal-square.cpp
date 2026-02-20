class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int>>dp(r+1, vector<int>(c+1, 0));
        int size = 0;
        for(int i=r-1; i>=0; i--){
            for(int j=c-1; j>=0; j--){
                if(matrix[i][j]=='1'){
                    dp[i][j] = min({dp[i+1][j], dp[i][j+1], dp[i+1][j+1]})+1;
                    size = max(size, dp[i][j]);
                }
            }
        }
        return size*size;
    }
};