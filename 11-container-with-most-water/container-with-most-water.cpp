class Solution {
public:
    int maxArea(vector<int>& nums) {
        int s=0, e=nums.size()-1;
        int ans = 0;
        while(s<e){
            ans = max(ans, min(nums[s], nums[e])*(e-s));
            if(nums[s]<nums[e])s++;
            else e--;
        }
        return ans;
    }
};