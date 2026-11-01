class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        long long sum = 0;
        for(int num:nums){
            mini = min(mini, num);
            sum+=num;
        }
        return sum - (mini*n);
    }
};