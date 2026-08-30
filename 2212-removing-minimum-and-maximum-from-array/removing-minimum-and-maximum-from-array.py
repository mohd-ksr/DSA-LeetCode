class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n = len(nums)
        minInd = nums.index(min(nums))
        maxInd = nums.index(max(nums))
        i, j = min(minInd, maxInd), max(minInd, maxInd)
        return min(j + 1, n - i, (i + 1) + (n - j))