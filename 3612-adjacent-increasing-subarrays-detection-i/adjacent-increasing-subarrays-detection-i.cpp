class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> inc(n, 1);
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1])
                inc[i] = inc[i - 1] + 1;
        }

        for (int a = 0; a + 2 * k <= n; ++a) {
            if (inc[a + k - 1] >= k && inc[a + 2 * k - 1] >= k)
                return true;
        }

        return false;
    }
};
