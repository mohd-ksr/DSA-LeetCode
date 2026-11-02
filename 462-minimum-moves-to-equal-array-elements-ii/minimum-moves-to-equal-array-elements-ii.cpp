class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int med;
        if(n%2==0){
            med = (nums[n/2] + nums[n/2 - 1])/2;
        }
        else{
            med = nums[n/2];
        }
        int ans = 0;
        for(auto num:nums){
            ans+=abs(med-num);
        }
        return ans;
    }
};