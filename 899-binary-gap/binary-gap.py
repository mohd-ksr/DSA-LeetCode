class Solution:
    def binaryGap(self, n: int) -> int:
        s = ""
        while n:
            s += str(n & 1)
            n >>= 1
        
        prev = -1
        ans = 0
        
        for i in range(len(s)):
            if s[i] == '1':
                if prev != -1:
                    ans = max(ans, i - prev)
                prev = i
        
        return ans