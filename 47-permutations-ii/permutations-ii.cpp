class Solution {
public:
    void backtrack(vector<int>&nums, int start, vector<vector<int>>&result){
        if(start==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=start; i<nums.size(); i++){
            swap(nums[start],nums[i]);
            backtrack(nums,start+1,result);
            swap(nums[start],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums,0,result);
        set<vector<int>>s(result.begin(),result.end());
        vector<vector<int>>result1(s.begin(),s.end());
        return result1; 
    }
};
// Time Complexity O(n! * n)
// Space Complexity O(n! * n)