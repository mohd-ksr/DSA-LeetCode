class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minInd = 0, maxInd = 0;
        int mini = nums[0], maxi = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < mini) { mini = nums[i]; minInd = i; }
            if (nums[i] > maxi) { maxi = nums[i]; maxInd = i; }
        }
        int i = min(minInd, maxInd);
        int j = max(minInd, maxInd);
        return min({j + 1, n - i, (i + 1) + (n - j)});
    }
};