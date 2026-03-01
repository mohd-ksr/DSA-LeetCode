class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        int i = 1, j = n-2;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])return mid;
            else if(nums[mid]>nums[mid-1])i=mid+1;
            else j=mid-1;
        }
        return -1;
    }
};