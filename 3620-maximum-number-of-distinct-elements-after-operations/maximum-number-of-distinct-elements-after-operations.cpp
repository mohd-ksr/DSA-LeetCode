class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long long cur = LLONG_MIN / 2;  
        int count = 0;
        
        for (long long x : nums) {
            long long left = x - k;
            long long right = x + k;
            
            long long new_val = max(cur + 1, left);
            
            if (new_val <= right) {
                count++;
                cur = new_val;
            }
        }
        
        return count;
    }
};
// Time complexiy O(nlogn)​