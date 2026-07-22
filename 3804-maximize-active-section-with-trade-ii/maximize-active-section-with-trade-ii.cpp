class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length(), m = queries.size();
        int cnt1 = count(s.begin(), s.end(), '1');

        vector<int> left(n, -1), right(n, -1);

        for (int i = 0; i < n; i++) {
            left[i] = (i > 0 && s[i - 1] == s[i]) ? left[i - 1] + 1 : 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            right[i] = (i < n - 1 && s[i + 1] == s[i]) ? right[i + 1] + 1 : 1;
        }

        vector<int> ans(m, -1);
        int block_size = (int)sqrt(n);
        vector<tuple<int, int, int, int>> longQueries;

        auto brute_force = [&](int l, int r) -> int {
            int i = l;
            int best = 0;
            int prev = INT_MIN;

            while (i <= r) {
                int start = i;
                while (i <= r && s[i] == s[start]) {
                    i++;
                }
                if (s[start] == '0') {
                    int cur = i - start;
                    best = (prev != INT_MIN && prev + cur > best) ? prev + cur : best;
                    prev = cur;
                }
            }
            return best;
        };

        for (int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];
            if (r - l + 1 > block_size) {
                longQueries.push_back({l / block_size, l, r, i});
            } else {
                ans[i] = cnt1 + brute_force(l, r);
            }
        }

        sort(longQueries.begin(), longQueries.end(),
             [](const tuple<int, int, int, int>& a,
                const tuple<int, int, int, int>& b) {
                 if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
                 return get<2>(a) < get<2>(b);
             });

        deque<int> subZeroBlocks;
        int L = 0, R = 0, bestGain = 0;

        for (int i = 0; i < longQueries.size(); i++) {
            int bid = get<0>(longQueries[i]);
            int l = get<1>(longQueries[i]);
            int r = get<2>(longQueries[i]);
            int qid = get<3>(longQueries[i]);

            if (i == 0 || bid > get<0>(longQueries[i - 1])) {
                L = (bid + 1) * block_size - 1;
                R = (bid + 1) * block_size;
                subZeroBlocks.clear();
                bestGain = 0;
            }

            while (R <= r) {
                int sz = min(r - R + 1, right[R]);
                if (s[R] == '0') {
                    if (!subZeroBlocks.empty() && s[R - 1] == '0') {
                        subZeroBlocks.back() += sz;
                    } else {
                        subZeroBlocks.push_back(sz);
                    }
                    if (subZeroBlocks.size() >= 2) {
                        bestGain = max(subZeroBlocks.back() +
                                           subZeroBlocks[subZeroBlocks.size() - 2],
                                       bestGain);
                    }
                }
                R += sz;
            }

            int tmp_bestGain = bestGain;
            int tmp_firstValue = subZeroBlocks.empty() ? -1 : subZeroBlocks.front();
            int cnt = 0;

            while (L >= l) {
                int sz = min(L - l + 1, left[L]);
                if (s[L] == '0') {
                    if (!subZeroBlocks.empty() && s[L + 1] == '0') {
                        subZeroBlocks.front() += sz;
                    } else {
                        subZeroBlocks.push_front(sz);
                        cnt++;
                    }
                    if (subZeroBlocks.size() >= 2) {
                        bestGain = max(subZeroBlocks[0] + subZeroBlocks[1], bestGain);
                    }
                }
                L -= sz;
            }

            ans[qid] = bestGain + cnt1;

            L = (bid + 1) * block_size - 1;
            bestGain = tmp_bestGain;

            for (int j = 0; j < cnt; j++) {
                subZeroBlocks.pop_front();
            }

            if (tmp_firstValue != -1) {
                subZeroBlocks[0] = tmp_firstValue;
            }
        }

        return ans;
    }
};