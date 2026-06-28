class Solution {
private:
    bool isPossible(vector<int>& ranks, int cars, long long time) {
        for (int r : ranks) {
            cars -= (long long)sqrt((long double)time / r);
            if (cars <= 0) return true;
        }
        return false;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        int mnRank = *min_element(ranks.begin(), ranks.end());

        long long l = 0;
        long long h = 1LL * mnRank * cars * cars;
        long long ans = h;

        while (l <= h) {
            long long mid = l + (h - l) / 2;

            if (isPossible(ranks, cars, mid)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};