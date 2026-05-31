class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        for(auto n:nums){
            ans = min(ans, n);
        }
        return ans;
    }
};