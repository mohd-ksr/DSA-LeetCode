var concatenatedBinary = function(n) {
    const MOD = 1_000_000_007n;
    let ans = 0n;
    for (let i = 1; i <= n; i++) {
        const nob = BigInt(Math.floor(Math.log2(i)) + 1);
        ans = ((ans << nob) | BigInt(i)) % MOD;
    }
    return Number(ans);
};