class Solution {
private:
    const long long mod = 1e9+7;
    int numberOfBits(int n){
        if(n==0)return 0;
        return 32 - __builtin_clz(n);
    }
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        for(int i=1; i<=n; i++){
            int nob = numberOfBits(i);
            ans = ((ans << nob) | i)%mod;
        }
        return ans;
    }
};