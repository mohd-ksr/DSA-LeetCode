class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        nums.sort()
        n = len(nums[0])
        for i in range(len(nums)):
            x = format(i, f'0{n}b')
            if x != nums[i]:
                return x
        return format(len(nums), f'0{n}b')