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
        unordered_map<long long,long long> freq;

        set<pair<long long,long long>, Comp> top;   
        set<pair<long long,long long>, Comp> rest; 
        long long topSum = 0;

        auto removeOldPair = [&](long long val, long long oldf) {
            if (oldf <= 0) return;
            pair<long long,long long> p = {oldf, val};
            auto it = top.find(p);
            if (it != top.end()) {
                topSum -= it->first * it->second; 
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
            while ((int)top.size() < x && !rest.empty()) {
                auto best = *rest.begin();
                rest.erase(rest.begin());
                top.insert(best);
                topSum += best.first * best.second;
            }
            while (!rest.empty() && !top.empty()) {
                auto bestRest = *rest.begin();
                auto worstTopIt = prev(top.end());
                auto worstTop = *worstTopIt;
                Comp cmp;
                if (cmp(bestRest, worstTop)) {
                    rest.erase(rest.begin());
                    top.erase(worstTopIt);
                    top.insert(bestRest);
                    rest.insert(worstTop);
                    topSum += bestRest.first * bestRest.second;
                    topSum -= worstTop.first * worstTop.second;
                } else break;
            }
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
            removeOldPair(v, oldf);
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
