class Solution {
    private final long MOD = 1_000_000_007;

    private int numberOfBits(int n) {
        if (n == 0) return 0;
        return 32 - Integer.numberOfLeadingZeros(n);
    }

    public int concatenatedBinary(int n) {
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            int nob = numberOfBits(i);
            ans = ((ans << nob) | i) % MOD;
        }
        return (int) ans;
    }
}