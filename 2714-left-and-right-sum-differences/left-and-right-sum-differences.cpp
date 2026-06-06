class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>rightSum(n);
        int sum=0;
        for(int i=n-1; i>=0; i--){
            rightSum[i]=sum;
            sum+=nums[i];
        }
        sum=0;
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            ans[i]=abs(sum-rightSum[i]);
            sum+=nums[i];
        }
        return ans;
    }
};