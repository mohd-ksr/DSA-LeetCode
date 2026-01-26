class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        for(int &num:nums)totalSum+=(long long)num;

        int count = 0;
        long long sum = 0;
        for(int i=0; i<n-1; i++){
            sum+=nums[i];
            if(sum>=(totalSum-sum))count++;
        }
        return count;
    }
};