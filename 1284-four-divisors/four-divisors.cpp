class Solution {
public:
    vector<bool> sieve;
    
    void buildSieve(int n) {
        sieve = vector<bool>(n + 1, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }

    bool isPrime(int x) {
        if (x < sieve.size()) return sieve[x];
        return false;
    }

    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        int maxNum = 0;
        for (int x : nums) maxNum = max(maxNum, x);
        
        buildSieve(maxNum);

        for (int x : nums) {
            int p = round(cbrt(x));
            if (p * p * p == x && isPrime(p)) {
                totalSum += (1 + p + p*p + x);
                continue;
            }
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    int j = x / i;
                    if (i != j && isPrime(i) && isPrime(j)) {
                        totalSum += (1 + i + j + x);
                    }
                    break;
                }
            }
        }

        return totalSum;
    }
};