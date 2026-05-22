class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0;
        double ans = INT_MIN;
        int i=0,j=0;
        for(;j<n;){
            sum+=nums[j];
            if((j-i+1)>k){
                sum-=nums[i++];
            }
            if((j-i+1)==k){
                ans = max(ans,sum/k);
            }
            j++;
        }
        return ans;
    }
};