class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mapp;
        for(int i=0; i<nums.size(); i++){
            int x=nums[i];
            if(mapp.find(target-x)!=mapp.end()){
                return {mapp[target-x], i};
            }
            mapp[x]=i;
        }
        return {};
    }
};