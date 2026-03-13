class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int>mapp;
        mapp[0]=1;
        int ans=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(mapp.find(sum-goal)!=mapp.end()){
                ans+=mapp[sum-goal];
            }
            mapp[sum]++;
        }
        return ans;
    }
};