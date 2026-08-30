/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDeletions = function(nums) {
    const n = nums.length;
    let minInd = 0, maxInd = 0;
    let mini = nums[0], maxi = nums[0];
    for (let i = 1; i < n; i++) {
        if (nums[i] < mini) { mini = nums[i]; minInd = i; }
        if (nums[i] > maxi) { maxi = nums[i]; maxInd = i; }
    }
    const i = Math.min(minInd, maxInd);
    const j = Math.max(minInd, maxInd);
    return Math.min(j + 1, n - i, (i + 1) + (n - j));
};