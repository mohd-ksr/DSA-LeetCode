class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        for(int n:nums)mini=min(mini,n);
        int ans = 0;
        for(int n:nums)ans+=n-mini;
        return ans;
    }
};
// Time Complexity O(n)