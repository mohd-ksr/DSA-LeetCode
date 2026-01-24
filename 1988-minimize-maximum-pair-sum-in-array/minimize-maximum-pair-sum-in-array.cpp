class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int s=0, e=n-1;
        int ans = -1;
        while(s<e){
            ans = max(ans, nums[s]+nums[e]);
            s++;e--;
        }
        return ans;
    }
};