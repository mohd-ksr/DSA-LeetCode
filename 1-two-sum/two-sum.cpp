class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mapp;
        for(int i=0; i<nums.size();i++){
            int compliment = target-nums[i];
            if(mapp.find(compliment)!=mapp.end()){
                return {mapp[compliment], i};
            }
            else mapp[nums[i]]=i;
        }
        return {}; // dummy
        
    }
};
// Time Complexity O(n)
// space Complexity O(n)
