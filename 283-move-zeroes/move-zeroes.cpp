class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ind = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]!=0)nums[ind++]=nums[i];
        }
        while(ind<n)nums[ind++]=0;
    }
};
// Time complexity O(n)