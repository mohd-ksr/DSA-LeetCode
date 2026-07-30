class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int d = n/8;
        int r = n%8;
        int ans = 4*d*(d+1);
        ans += (d+1)*r;
        return ans;
    }
};