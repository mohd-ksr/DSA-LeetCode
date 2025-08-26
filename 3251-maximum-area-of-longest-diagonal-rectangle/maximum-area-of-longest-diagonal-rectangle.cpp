class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double digLen = 0.0;
        int ans = 0;
        for (auto &sq : dimensions) {
            double curDiag = sqrt(sq[0] * sq[0] + sq[1] * sq[1]);
            int curArea = sq[0] * sq[1];
            if (curDiag > digLen || (fabs(curDiag - digLen) < 1e-9 && curArea > ans)) {
                digLen = curDiag;
                ans = curArea;
            }
        }
        return ans;
    }
};

// Time complexity O(n)
// Space complexity O(1)