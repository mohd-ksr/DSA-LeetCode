struct Fenwick {
    int n;
    vector<int> bit; 
    Fenwick(int n): n(n), bit(n+1, 0) {}
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] = max(bit[idx], val);
    }
    int query(int idx) { 
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

        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
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
        for (int i = 0; i < n; ++i) {
            Fenwick fw((int)ys.size());
            for (int j = i + 1; j < n; ++j) {
                if (points[i][1] >= points[j][1]) {
                    int maxCY = fw.query(cy[i]);
                    if (maxCY < cy[j]) ans++;
                }
                fw.update(cy[j], cy[j]);
            }
        }
        return ans;
    }
};
// Time Complexity O(n2logn)
// Space Complexity O(n)
