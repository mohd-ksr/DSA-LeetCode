// class Solution {
// private:
//     void solve(int i, vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans){
//         if(i==nums.size()){
//             ans.push_back(temp);
//             return;
//         }
//         temp.push_back(nums[i]);
//         solve(i+1,nums,temp,ans);
//         temp.pop_back();
//         solve(i+1,nums,temp,ans);
//     }
// public:
//     vector<vector<int>> combinationSum(vector<int>& nums, int target) {
//         vector<vector<int>>ans;
//         vector<int>temp;
//         solve(0,nums,temp,ans);
//         return ans;
//     }
// };


class Solution {
private:
    void calculate(int i,int target,vector<int>& candidates,vector<vector<int>>&ans,vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i==candidates.size()||target<0)return;

        temp.push_back(candidates[i]);
        calculate(i,target-candidates[i],candidates,ans,temp);
        temp.pop_back();
        calculate(i+1,target,candidates,ans,temp);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        calculate(0,target,candidates,ans,temp);
        return ans;
    }
};
// Time Complexity O(2^t) // where t is target/min(candidates[i])
// Space Complexity O(t)