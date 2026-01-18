class Solution {
private:
    void cal(vector<int>& nums,int i, vector<vector<int>>&ans, vector<int>temp){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        cal(nums,i+1, ans, temp);
        temp.push_back(nums[i]);
        cal(nums,i+1, ans,temp);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        cal(nums, 0, ans, {});
        return ans;
    }
};