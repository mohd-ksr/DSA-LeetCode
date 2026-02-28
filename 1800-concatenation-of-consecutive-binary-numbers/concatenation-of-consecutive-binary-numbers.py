class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MOD = 10**9 + 7
        ans = 0
        for i in range(1, n + 1):
            nob = i.bit_length()
            ans = ((ans << nob) | i) % MOD
        return ans