class Solution {
private:
    int count(vector<vector<int>>& matrix, int mid){
        int n=matrix.size();
        int c=0;
        int row = n-1, col=0;
        while(row>=0 && col<n){
            if(matrix[row][col]<=mid){
                c+=row+1;
                col++;
            }
            else row--;
        } 
        return c;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int s=matrix[0][0], e=matrix[n-1][n-1];
        while(s<e){
            int mid = s+(e-s)/2;
            int c = count(matrix, mid);
            if(c<k)s=mid+1;
            else e=mid;
        }
        return s;
    }
};