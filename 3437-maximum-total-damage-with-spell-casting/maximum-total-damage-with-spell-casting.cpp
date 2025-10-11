class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> freq;
        for (int p : power) freq[p]++;

        vector<long long> keys;
        for (auto &it : freq) keys.push_back(it.first);
        sort(keys.begin(), keys.end());

        int n = keys.size();
        vector<long long> dp(n, 0);
        dp[0] = keys[0] * freq[keys[0]];

        for (int i = 1; i < n; i++) {
            long long include = keys[i] * freq[keys[i]];
            int j = i - 1;
            while (j >= 0 && keys[i] - keys[j] <= 2) j--;
            if (j >= 0) include += dp[j];
            dp[i] = max(dp[i-1], include);
        }
        return dp[n-1];
    }
};