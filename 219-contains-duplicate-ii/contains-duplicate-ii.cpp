class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mapp;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(mapp.find(nums[i])!=mapp.end()){
                if(abs(i-mapp[nums[i]])<=k)return true;
            }
            mapp[nums[i]]=i;
        }
        return false;
    }
};