class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0.0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    auto &A=points[i];
                    auto &B=points[j];
                    auto &C=points[k];

                    ans=max(ans, 0.5*abs(A[0]*(B[1]-C[1]) + B[0]*(C[1]-A[1]) + C[0]*(A[1]-B[1])));
                }
            }
        }
        return ans;
    }
};
// Time Complexity O(n^3)