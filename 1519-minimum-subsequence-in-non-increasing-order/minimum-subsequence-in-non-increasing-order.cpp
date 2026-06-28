class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long totalSum = 0;
        for(auto num:nums)totalSum+=num;
        long long sum=0;
        vector<int> ans;
        for(int i=nums.size()-1; i>=0; i--){
            sum+=nums[i];
            ans.push_back(nums[i]);
            if(totalSum < 2*sum)break;
        }
        return ans;
    }
};