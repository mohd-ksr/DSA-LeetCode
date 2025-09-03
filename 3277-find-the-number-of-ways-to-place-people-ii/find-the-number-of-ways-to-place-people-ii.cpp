
// Fenwick (BIT) supporting prefix maximum
struct Fenwick {
    int n;
    vector<int> bit; // stores max over prefix
    Fenwick(int n): n(n), bit(n+1, 0) {}
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] = max(bit[idx], val);
    }
    int query(int idx) { // max over [1..idx]
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res = max(res, bit[idx]);
        return res;
    }
};

class Solution {
public:
    long long numberOfPairs(vector<vector<int>>& points) {
        int n = (int)points.size();

        // 1) Sort by x asc, y desc
        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        // 2) Coordinate-compress y
        vector<long long> ys;
        ys.reserve(n);
        for (auto &p: points) ys.push_back(p[1]);
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        auto comp = [&](long long y){
            return (int)(lower_bound(ys.begin(), ys.end(), y) - ys.begin()) + 1; // 1-based
        };

        vector<int> cy(n);
        for (int i = 0; i < n; ++i) cy[i] = comp(points[i][1]);

        long long ans = 0;

        // 3) For each Alice i, scan j>i; maintain blockers from (i+1..j-1)
        for (int i = 0; i < n; ++i) {
            Fenwick fw((int)ys.size());
            // IMPORTANT: do NOT insert Alice (i) into fenwick
            for (int j = i + 1; j < n; ++j) {
                // Alice must be upper-left of Bob
                if (points[i][1] >= points[j][1]) {
                    // Max compressed y among points between i and j with y <= y[i]
                    int maxCY = fw.query(cy[i]);
                    // valid if no blocker with y in [y[j], y[i]] -> i.e., maxCY < cy[j]
                    if (maxCY < cy[j]) ans++;
                }
                // After checking j, insert j as potential blocker for later Bobs
                fw.update(cy[j], cy[j]);
            }
        }
        return ans;
    }
};
