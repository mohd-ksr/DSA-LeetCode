class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i)
            pref[i + 1] = pref[i] + skill[i];

        vector<long long> prevC(n, 0), currC(n, 0);
        long long start = 0;
        for (int i = 0; i < n; ++i)
            currC[i] = start + mana[0] * pref[i + 1];
        prevC = currC;
        for (int j = 1; j < m; ++j) {
            long long startNeeded = LLONG_MIN;
            for (int i = 0; i < n; ++i)
                startNeeded = max(startNeeded, prevC[i] - mana[j] * pref[i]);
            start = max(0LL, startNeeded);
            for (int i = 0; i < n; ++i)
                currC[i] = start + mana[j] * pref[i + 1];

            prevC = currC;
        }
        return prevC.back();
    }
};