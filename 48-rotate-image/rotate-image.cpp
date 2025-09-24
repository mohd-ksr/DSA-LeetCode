class Solution {
private:
    void reverse(vector<int>&arr){
        int n=arr.size();
        for(int i=0; i<n/2; i++){
            swap(arr[i],arr[n-i-1]);
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            reverse(matrix[i]);
        }
    }
};
// Time Complexity O(n²)
// Space Complexity O(1)