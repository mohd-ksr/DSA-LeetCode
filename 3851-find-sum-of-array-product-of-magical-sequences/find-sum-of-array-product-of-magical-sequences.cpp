class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int L = 0;
        while ((1 << L) <= m) ++L;
        int MASK_SIZE = 1 << L;
        vector<long long> fact(m + 1, 1), invfact(m + 1, 1);
        auto modpow = [&](long long a, long long b) -> long long {
            long long res = 1;
            while (b) {
                if (b & 1) res = res * a % MOD;
                a = a * a % MOD;
                b >>= 1;
            }
            return res;
        };

        for (int i = 1; i <= m; ++i) fact[i] = fact[i - 1] * i % MOD;
        invfact[m] = modpow(fact[m], MOD - 2);
        for (int i = m - 1; i >= 0; --i) invfact[i] = invfact[i + 1] * (i + 1) % MOD;

        auto C = [&](int a, int b) -> long long {
            if (b < 0 || b > a) return 0;
            return fact[a] * invfact[b] % MOD * invfact[a - b] % MOD;
        };

        // Precompute nums[i]^c for all c
        vector<vector<long long>> pow_num(n, vector<long long>(m + 1, 1));
        for (int i = 0; i < n; ++i)
            for (int c = 1; c <= m; ++c)
                pow_num[i][c] = pow_num[i][c - 1] * nums[i] % MOD;

        using Key = tuple<int, int, int>;
        struct KeyHash {
            size_t operator()(const Key& k) const noexcept {
                auto [a, b, c] = k;
                return ((a * 31 + b) * 131) ^ c;
            }
        };

        unordered_map<Key, long long, KeyHash> cur, nxt;
        cur[{0, 0, 0}] = 1;

        for (int idx = 0; idx < n; ++idx) {
            nxt.clear();
            for (auto& [key, val] : cur) {
                auto [t, ones, mask] = key;
                if (val == 0) continue;
                int max_take = m - t;

                for (int c = 0; c <= max_take; ++c) {
                    int t2 = t + c;
                    long long ways_insert = C(t + c, c);
                    long long prod_factor = pow_num[idx][c];
                    long long add_val = val * ways_insert % MOD * prod_factor % MOD;

                    int temp = mask + c;
                    int bit = temp & 1;
                    int ones2 = ones + bit;
                    if (ones2 > k) continue;
                    int mask2 = (temp >> 1) & (MASK_SIZE - 1);

                    auto key2 = make_tuple(t2, ones2, mask2);
                    nxt[key2] = (nxt[key2] + add_val) % MOD;
                }
            }
            cur.swap(nxt);
        }

        long long ans = 0;
        for (auto& [key, val] : cur) {
            auto [t, ones, mask] = key;
            if (t != m) continue;
            int total_ones = ones + __builtin_popcount(mask);
            if (total_ones == k) ans = (ans + val) % MOD;
        }

        return (int)ans;
    }
};
