class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int sr=0;
        int sc=0;
        int er=row-1;
        int ec=col-1;
        int count=0;
        int maxCount=row*col;
        vector<int>ans;
        while(count<maxCount){
            for(int i=sc; i<=ec && count<maxCount; i++){
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;
            for(int i=sr; i<=er && count<maxCount; i++){
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
            for(int i=ec; i>=sc && count<maxCount; i--){
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;
            for(int i=er; i>=sr && count<maxCount; i--){
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
        }
        return ans;
    }
};
// Time Complexity O(mxn)
// Time Complexity O(mxn) for answer vector