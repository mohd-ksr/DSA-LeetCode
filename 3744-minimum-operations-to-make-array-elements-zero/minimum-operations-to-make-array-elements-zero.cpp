class Solution {
private:
   private:
    long long prefixSum(long long n) {
        if (n <= 0) return 0;
        long long total = 0;
        long long k = 1;
        long long start = 1;
        while (start <= n) {
            long long end = min(n, (1LL << (2*k)) - 1); 
            long long count = end - start + 1;
            total += count * k;
            start <<= 2;
            k++;
        }
        return total;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
         long long sum = 0;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long steps = prefixSum(r) - prefixSum(l-1);
            sum += (steps + 1) / 2; 
        }
        return sum;
    }
};
// Time Complexity O(Q log n)
// Space complexity O(1)