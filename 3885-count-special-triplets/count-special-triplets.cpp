class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> mapp;
        for (int n : nums) {
            mapp[n]++;
        }
        unordered_map<int, int> prefix;
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (int n : nums) {
            int t = mapp[2 * n];
            int l = prefix[2 * n];
            int r = t - l;
            if (n == 0) {
                r--;
            }

            prefix[n]++;

            ans = (ans + l * 1LL * r) % mod;
        }
        return ans;
    }
};