class Solution {
private:
    void rev(int s, int e, vector<int>&nums){
        while(s<e){
            swap(nums[s++],nums[e--]);
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        rev(0, nums.size()-1, nums);
        rev(0, k-1, nums);
        rev(k, nums.size()-1, nums);
    }
};