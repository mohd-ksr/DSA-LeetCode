class Solution {
public:
    int findMin(vector<int>& nums) { return dnc(0, nums.size() - 1, nums); }

    int dnc(int left, int right, vector<int>& nums) {
        if (left == right)
            return nums[left];

        if (nums[left] < nums[right])
            return nums[left];

        int m = (left + right) >> 1;

        return min(dnc(left, m, nums), dnc(m + 1, right, nums));
    }
};