struct Comp {
    bool operator()(const pair<long long,long long>& a, const pair<long long,long long>& b) const {
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> ans;
        unordered_map<long long,long long> freq; // value -> count

        set<pair<long long,long long>, Comp> top;   // top x by (freq, value)
        set<pair<long long,long long>, Comp> rest;  // the others
        long long topSum = 0;

        auto removeOldPair = [&](long long val, long long oldf) {
            if (oldf <= 0) return;
            pair<long long,long long> p = {oldf, val};
            auto it = top.find(p);
            if (it != top.end()) {
                topSum -= it->first * it->second; // freq * val
                top.erase(it);
            } else {
                auto it2 = rest.find(p);
                if (it2 != rest.end()) rest.erase(it2);
            }
        };

        auto insertNewPairAsRest = [&](long long val, long long f) {
            if (f <= 0) return;
            rest.insert({f, val});
        };

        auto rebalance = [&]() {
            // Fill top up to x from rest
            while ((int)top.size() < x && !rest.empty()) {
                auto best = *rest.begin();
                rest.erase(rest.begin());
                top.insert(best);
                topSum += best.first * best.second;
            }
            // Ensure every element in top is better than every element in rest
            while (!rest.empty() && !top.empty()) {
                auto bestRest = *rest.begin();
                auto worstTopIt = prev(top.end());
                auto worstTop = *worstTopIt;
                // if bestRest is better (cmp says comes earlier) than worstTop, swap them
                // comparator orders higher first; so compare using Comp()
                Comp cmp;
                // bestRest better than worstTop if cmp(bestRest, worstTop) == true
                if (cmp(bestRest, worstTop)) {
                    // swap
                    rest.erase(rest.begin());
                    top.erase(worstTopIt);
                    top.insert(bestRest);
                    rest.insert(worstTop);
                    topSum += bestRest.first * bestRest.second;
                    topSum -= worstTop.first * worstTop.second;
                } else break;
            }
            // If top has more than x (possible if we removed others incorrectly), move worst to rest
            while ((int)top.size() > x) {
                auto worstTopIt = prev(top.end());
                auto worstTop = *worstTopIt;
                top.erase(worstTopIt);
                rest.insert(worstTop);
                topSum -= worstTop.first * worstTop.second;
            }
        };

        for (int i = 0; i < n; ++i) {
            long long v = nums[i];
            long long oldf = freq[v];
            // remove old pair (from top or rest)
            removeOldPair(v, oldf);
            // update freq and insert new as rest (we always insert into rest and then rebalance)
            freq[v] = oldf + 1;
            insertNewPairAsRest(v, freq[v]);

            if (i >= k) {
                long long out = nums[i - k];
                long long oldfo = freq[out];
                removeOldPair(out, oldfo);
                freq[out] = oldfo - 1;
                if (freq[out] > 0) insertNewPairAsRest(out, freq[out]);
                else freq.erase(out);
            }

            rebalance();
            if (i >= k - 1) ans.push_back(topSum);
        }

        return ans;
    }
};
