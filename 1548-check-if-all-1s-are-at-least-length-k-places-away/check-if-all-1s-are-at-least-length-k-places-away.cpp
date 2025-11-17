class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ind;
        for(int i=0; i<n; i++){
            if(nums[i]==1)ind.push_back(i);
        }
        for(int i=1; i<ind.size(); i++){
            if((ind[i]-ind[i-1]-1) < k)return false;
        }
        return true;
    }
};