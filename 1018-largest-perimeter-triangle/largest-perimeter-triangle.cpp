class Solution {
public:
    int largestPerimeter(vector<int> nums) {
        int n = nums.size();
        if(n<3)return 0;
        sort(nums.begin(), nums.end());
        int i=n-3;
        int j=n-2;
        int k=n-1;
        while(i>=0){
            if(nums[i]+nums[j]>nums[k])break;
            i--;j--;k--;
        }
        return i>=0?nums[i]+nums[j]+nums[k]:0;
    }
};
// Time complexity O(n)