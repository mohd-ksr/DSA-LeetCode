class Solution {
public:
    int majorityElement(vector<int>& nums) {       
        int majority = nums[0], count = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == majority){
                count = count + 1;
            }
            else if(nums[i]!=majority){
                if(count!=0){
                    count = count - 1;
                }
                else{
                    majority = nums[i];
                    count = 1;
                }
            }
        }
        return majority;
    }
};
// Time complexity O(n)
// space complexity O(1)