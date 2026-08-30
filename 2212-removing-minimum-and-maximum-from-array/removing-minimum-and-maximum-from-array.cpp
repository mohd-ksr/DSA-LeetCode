class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minInd = 0;
        int maxInd = 0;
        int mini = nums[0];
        int maxi = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]<mini){
                mini = nums[i];
                minInd = i;
            }
            if(nums[i]>maxi){
                maxi = nums[i];
                maxInd = i;
            }
        }
        int ans = min({max(minInd, maxInd)+1, n-min(minInd, maxInd), minInd+1+n-maxInd, n-minInd+maxInd+1});
        return ans;
    }
};