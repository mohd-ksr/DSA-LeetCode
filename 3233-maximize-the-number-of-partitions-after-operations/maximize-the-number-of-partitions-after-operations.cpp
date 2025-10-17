class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = (int)s.size();
        vector<array<int,26>> prefCnt(n+1);
        prefCnt[0].fill(0);
        for (int i = 0; i < n; ++i) {
            prefCnt[i+1] = prefCnt[i];
            prefCnt[i+1][s[i]-'a']++;
        }

        auto distinctOrig = [&](int L, int R)->int {
            int d = 0;
            for (int c = 0; c < 26; ++c)
                if (prefCnt[R+1][c] - prefCnt[L][c] > 0) d++;
            return d;
        };

        auto distinctWithChange = [&](int L, int R, int i, int newC)->int {
            if (i < L || i > R) {
                return distinctOrig(L, R);
            }
            int a = s[i] - 'a';
            if (newC == a) {
                return distinctOrig(L, R);
            }
            int d = 0, cntA = 0, cntB = 0;
            for (int c = 0; c < 26; ++c) {
                int cnt = prefCnt[R+1][c] - prefCnt[L][c];
                if (cnt > 0) d++;
            }
            cntA = prefCnt[R+1][a] - prefCnt[L][a];
            cntB = prefCnt[R+1][newC] - prefCnt[L][newC];
            if (cntA == 1) d--;
            if (cntB == 0) d++;
            return d;
        };

        vector<int> next_break(n);
        {
            array<int,26> freq{}; freq.fill(0);
            int distinct = 0;
            int r = 0;
            for (int l = 0; l < n; ++l) {
                while (r < n) {
                    int ch = s[r]-'a';
                    if (freq[ch] == 0 && distinct == k) break;
                    if (freq[ch] == 0) distinct++;
                    freq[ch]++;
                    r++;
                }
                next_break[l] = r; 
                int chL = s[l]-'a';
                freq[chL]--;
                if (freq[chL] == 0) distinct--;
            }
        }

        vector<int> partition_start(n, 0);
        vector<int> pref(n, 0);
        int total_orig = 0;
        {
            int start = 0, partIdx = 0;
            while (start < n) {
                int endEx = next_break[start]; 
                total_orig++;
                for (int i = start; i < endEx; ++i) {
                    partition_start[i] = start;
                    pref[i] = total_orig; 
                }
                start = endEx;
            }
        }

        vector<int> suff(n+1, 0); 
        for (int i = n-1; i >= 0; --i) {
            int j = next_break[i];
            suff[i] = 1 + suff[j];
        }
        suff[n] = 0; 
        int ans = total_orig;

        auto bsearchRight = [&](int L, int i, int newC)->int {
            int lo = L, hi = n-1, best = L-1; 
            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                int d = distinctWithChange(L, mid, i, newC);
                if (d <= k) {
                    best = mid;
                    lo = mid + 1;
                } else hi = mid - 1;
            }
            return best;
        };

        for (int i = 0; i < n; ++i) {
            int a = s[i] - 'a';
            int L = partition_start[i];
            for (int c = 0; c < 26; ++c) {
                if (c == a) continue;
                int r = bsearchRight(L, i, c);

                if (r >= i) {
                    int leftParts = (L > 0 ? pref[L-1] : 0);
                    int rightParts = suff[r+1];
                    ans = max(ans, 1 + leftParts + rightParts);
                } else {
                    int L2 = r + 1;
                    if (L2 >= n) {
                        int leftParts = (L > 0 ? pref[L-1] : 0);
                        ans = max(ans, 1 + leftParts);
                        continue;
                    }
                    int r2 = bsearchRight(L2, i, c);
                    int leftParts = (L > 0 ? pref[L-1] : 0);
                    int rightParts = suff[r2+1];
                    ans = max(ans, 2 + leftParts + rightParts);
                }
            }
        }

        return ans;
    }
};
