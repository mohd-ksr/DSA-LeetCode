class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1, suf = 1;
        int maxi = nums[0];

        for(int i=0; i<n; i++){
            pre = (pre==0? 1 : pre)*nums[i];
            suf = (suf==0? 1 : suf)*nums[n-1-i];
            maxi = max({maxi, pre, suf});
        }
        return maxi;
    }
};