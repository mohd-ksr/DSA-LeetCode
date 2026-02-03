class Solution {
public:
    bool isTrionic(vector<int>& nums) {
       int n = nums.size();
       int i=1;
       while(i<n && nums[i]>nums[i-1])i++;
       int p=i-1;
       while(i<n && nums[i]<nums[i-1])i++;
       int q=i-1;
       while(i<n && nums[i]>nums[i-1])i++;
    
       return (p!=0) && (p!=q) && (i==n && q!=i-1);
    }
};