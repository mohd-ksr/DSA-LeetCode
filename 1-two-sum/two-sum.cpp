class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mapp;
        vector<int>ans(2);
        for(int i=0; i<nums.size();i++){
            if(mapp.find(target-nums[i])!=mapp.end()){
                ans[0]=mapp[target-nums[i]];
                ans[1]=i;
            }
            else mapp[nums[i]]=i;
        }
        return ans;
        
    }
};
// Time Complexity O(n)
// space Complexity O(n)
