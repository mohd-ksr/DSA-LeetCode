class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int dec = 1;
        int maxInc = 0;
        int maxDec = 0;
        int n = nums.size();
        for(int i=1; i<n; i++){
            maxInc = max(maxInc, inc);
            maxDec = max(maxDec, dec);
            if(nums[i] > nums[i-1])inc++;
            else{
                inc = 1;
            }

            if(nums[i] < nums[i-1])dec++;
            else{
                dec = 1;
            }
        }
        return max({inc, dec, maxInc, maxDec});
    }
};