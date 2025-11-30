class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m = nums[0], c = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==m)c++;
            else{
                if(c!=0)c--;
                else{
                    m=nums[i];
                    c=1;
                }
            }
        }
        return m;
    }
};
// Time complexity O(n)
// space complexity O(1)