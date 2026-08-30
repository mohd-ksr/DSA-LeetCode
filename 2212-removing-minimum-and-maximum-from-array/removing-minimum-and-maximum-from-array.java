class Solution {
    public int minimumDeletions(int[] nums) {
        int n = nums.length;
        int minInd = 0, maxInd = 0;
        int mini = nums[0], maxi = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < mini) { mini = nums[i]; minInd = i; }
            if (nums[i] > maxi) { maxi = nums[i]; maxInd = i; }
        }
        int i = Math.min(minInd, maxInd);
        int j = Math.max(minInd, maxInd);
        return Math.min(j + 1, Math.min(n - i, (i + 1) + (n - j)));
    }
}