class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mapp;
        int ans = 0;
        int sum=0;
        mapp[0]=1;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(mapp.find(sum-k)!=mapp.end()){
                ans+=mapp[sum-k];
            }
            mapp[sum]++;
        }
        return ans;
    }
};